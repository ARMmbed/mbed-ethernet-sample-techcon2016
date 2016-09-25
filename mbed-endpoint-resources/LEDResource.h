/**
 * @file    LEDResource.h
 * @brief   mbed CoAP Endpoint LED resource supporting CoAP PUT
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

#ifndef __LED_RESOURCE_H__
#define __LED_RESOURCE_H__

// Base class
#include "mbed-connector-interface/DynamicResource.h"

// our LED sensor
DigitalOut  __light(LED3);

// possible LED states
#define OFF             "1"
#define ON              "0"

/** LEDResource class
 */
class LEDResource : public DynamicResource
{

public:
    /**
    Default constructor
    @param logger input logger instance for this resource
    @param obj_name input the LED Object name
    @param res_name input the LED Resource name
    @param observable input the resource is Observable (default: FALSE)
    */
    LEDResource(const Logger *logger,const char *obj_name,const char *res_name,const bool observable = false) : DynamicResource(logger,obj_name,res_name,"LED",M2MBase::PUT_ALLOWED,observable) {
    }

    /**
    Set the value of the LED
    @param string input the string containing "0" (light off) or "1" (light on)
    */
    virtual void put(const string value) {
        if (value.compare(string(OFF)) == 0) __light = 0;
        else __light = 1;
    }
};

#endif // __LED_RESOURCE_H__
