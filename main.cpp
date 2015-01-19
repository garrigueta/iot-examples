#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
 
int main(int argc,char** argv)
{
        struct termios tio;
        struct termios stdio;
        struct termios old_stdio;
        int tty_fd;
 
        unsigned char c='D';
        tcgetattr(STDOUT_FILENO,&old_stdio);
 
        printf("Please start with %s /dev/ttyS1 (for example)\n",argv[0]);
        memset(&stdio,0,sizeof(stdio));
        stdio.c_iflag=0;
        stdio.c_oflag=0;
        stdio.c_cflag=0;
        stdio.c_lflag=0;
        stdio.c_cc[VMIN]=1;
        stdio.c_cc[VTIME]=0;
        tcsetattr(STDOUT_FILENO,TCSANOW,&stdio);
        tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);       // make the reads non-blocking
 
        memset(&tio,0,sizeof(tio));
        tio.c_iflag=0;
        tio.c_oflag=0;
        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
        tio.c_lflag=0;
        tio.c_cc[VMIN]=1;
        tio.c_cc[VTIME]=5;
 
        tty_fd=open("/dev/ttyAMA0", O_RDWR | O_NONBLOCK);      
        cfsetospeed(&tio,B57600);            // 115200 baud
        cfsetispeed(&tio,B57600);            // 115200 baud
 
        tcsetattr(tty_fd,TCSANOW,&tio);
        while (c!='q')
        {
                if (read(tty_fd,&c,1)>0)        write(STDOUT_FILENO,&c,1);              // if new data is available on the serial port, print it out
                if (read(STDIN_FILENO,&c,1)>0)  write(tty_fd,&c,1);                     // if new data is available on the console, send it to the serial port
        }
 
        close(tty_fd);
        tcsetattr(STDOUT_FILENO,TCSANOW,&old_stdio);
 
        return EXIT_SUCCESS;
}
 /*
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
  */
