mbedConnectorInteface endpoint example for TechCon2016 (Ethernet)

You will need to replace the contents of security.h with yours. 

You can import this project into the online IDE at https://developer.mbed.org

 - Right-click on "My Project"

 - Select import "from URL" 

 - Enter the following URL: https://github.com/ARMmbed/mbed-ethernet-sample-techcon2016

 - DO NOT SELECT "Update all libraries"... ensure that remains UNCHECKED 
 
To compile locally, you need to install "mbed-cli"

Example (Linux):

 % pip install -U "mbed-cli"

Once installed:

 % git clone https://github.com/ARMmbed/mbed-ethernet-sample-techcon2016

 % cd mbed-ethernet-sample-techcon2016

 % mbed deploy

 % mbed target K64F

 % mbed toolchain GCC_ARM

 % mbed compile -m K64F -t GCC_ARM -c -j0

The compiled binary will be found in here:

 % ls -al .build/K64F/GCC_ARM/mbed-ethernet-sample-techcon2016.bin

Lastly, copy the "bin" file to your mbed device and reset the device
