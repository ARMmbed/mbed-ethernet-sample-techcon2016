/**
 * @file    main.cpp
 * @brief   mbed Endpoint Sample main
 * @author  Doug Anson
 * @version 1.0
 * @see
 *
 * Copyright (c) 2014
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Our device type
#define MY_DEVICE_TYPE	"mbed-endpoint"

// Include security.h
#include "security.h"

// mbed Endpoint Network
#include "mbed-connector-interface/mbedEndpointNetwork.h"

// Logger
#include "mbed-connector-interface/Logger.h"
Serial pc(USBTX,USBRX);
Logger logger(&pc);

// LED Resource
#include "mbed-endpoint-resources/LEDResource.h"
LEDResource led(&logger,"311","5850");

// Accelerometer Resource
#include "mbed-endpoint-resources/AccelerometerResource.h"
AccelerometerResource accel(&logger,"888","7700",true);        				// "true" --> resource is observable

// called from the Endpoint::start() below to create resources and the endpoint internals...
Connector::Options *configure_endpoint(Connector::OptionsBuilder &config)
{    
    // Build the endpoint configuration parameters
    logger.log("Endpoint::main (%s): customizing endpoint configuration...",net_get_type());
    return config                 
    	// PROVISIONING: set the Provisioning Credentials (all from security.h)
        .setEndpointNodename(MBED_ENDPOINT_NAME)                  			
        .setDomain(MBED_DOMAIN)
        .setEndpointType(MY_DEVICE_TYPE)                               							  
        .setServerCertificate((uint8_t *)SERVER_CERT,(int)sizeof(SERVER_CERT))
        .setClientCertificate((uint8_t *)CERT,(int)sizeof(CERT))
        .setClientKey((uint8_t *)KEY,(int)sizeof(KEY))

	// Set use of TCP or UDP for this endpoint
	//.setCoAPConnectionType(COAP_UDP)
	//.setCoAPConnectionType(COAP_TCP)
                
        // Add my specific physical resources...
        .addResource(&led)
        .addResource(&accel,(bool)false)			// on demand observation 						
                   
        // finalize the configuration...
        .build();
}

// main entry point...
int main()
{
    // set Serial
    pc.baud(115200);
	
    // Announce
    logger.log("\r\n\r\nmbed Connector Sample Endpoint - TechCon2016 (%s)",net_get_type());
    
    // we have to plumb our network first
    Connector::Endpoint::plumbNetwork();
    
    // starts the endpoint by finalizing its configuration (configure_endpoint() above gets called...)
    Connector::Endpoint::start();
}
