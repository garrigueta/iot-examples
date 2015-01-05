#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"
 
using namespace std;
 
int main (void)
{
 
    string inputstate;
    
    
    GPIOClass* gpio17 = new GPIOClass("17"); //create new GPIO object to be attached to  GPIO4
    GPIOClass* gpio27 = new GPIOClass("27"); //create new GPIO object to be attached to  GPIO17
    GPIOClass* gpio22 = new GPIOClass("22"); //create new GPIO object to be attached to  GPIO17
    GPIOClass* gpio23 = new GPIOClass("23"); //create new GPIO object to be attached to  GPIO17
    GPIOClass* gpio24 = new GPIOClass("24"); //create new GPIO object to be attached to  GPIO17
    GPIOClass* gpio25 = new GPIOClass("25"); //create new GPIO object to be attached to  GPIO17
    GPIOClass* gpio8 = new GPIOClass("8"); //create new GPIO object to be attached to  GPIO17
    GPIOClass* gpio7 = new GPIOClass("7");
    GPIOClass* gpio9 = new GPIOClass("9");
    GPIOClass* gpio10 = new GPIOClass("10");
    GPIOClass* gpio11 = new GPIOClass("11");
    GPIOClass* gpio18 = new GPIOClass("18");
 
    gpio17->export_gpio(); //export GPIO4
    gpio27->export_gpio(); //export GPIO17
    gpio22->export_gpio();
    gpio23->export_gpio();
    gpio24->export_gpio();
    gpio25->export_gpio();
    gpio8->export_gpio();
    gpio7->export_gpio();
    gpio9->export_gpio();
    gpio10->export_gpio();
    gpio11->export_gpio();
    gpio18->export_gpio();

    cout << " GPIO pins exported" << endl;
 
    gpio17->setdir_gpio("out"); //export GPIO4
    gpio27->setdir_gpio("out"); //export GPIO17
    gpio22->setdir_gpio("out");
    gpio23->setdir_gpio("out");
    gpio24->setdir_gpio("out");
    gpio25->setdir_gpio("out"); 
    gpio8->setdir_gpio("out");
    gpio7->setdir_gpio("out");
    gpio9->setdir_gpio("out");
    gpio10->setdir_gpio("out");
    gpio11->setdir_gpio("out");
    gpio18->setdir_gpio("out");
 
    cout << " Set GPIO pin directions" << endl;
 
    cout << " Switch GPIO pin on" << endl;
    
    usleep(150000);  // wait for 0.5 seconds
    gpio17->setval_gpio("1"); //export GPIO4
    usleep(150000);  // wait for 0.5 seconds
    gpio27->setval_gpio("1"); //export GPIO17
    usleep(150000);  // wait for 0.5 seconds
    gpio22->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio23->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio24->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio25->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio8->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio7->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio9->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio10->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio11->setval_gpio("1");
    usleep(150000);  // wait for 0.5 seconds
    gpio18->setval_gpio("1");
        
    cout << " Switch GPIO pin off" << endl;

    usleep(150000);  // wait for 0.5 seconds
    gpio17->setval_gpio("0"); //export GPIO4
    usleep(150000);  // wait for 0.5 seconds
    gpio27->setval_gpio("0"); //export GPIO17
    usleep(150000);  // wait for 0.5 seconds
    gpio22->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio23->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio24->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio25->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio8->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio7->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio9->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio10->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio11->setval_gpio("0");
    usleep(150000);  // wait for 0.5 seconds
    gpio18->setval_gpio("0");

    cout << "Exiting....." << endl;
    return 0;
}
