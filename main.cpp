#include "mduserhandle.h"

int main(int argc, char* argv[])

{

  CMduserHandler *mduser = new CMduserHandler;

  mduser->connect();

  mduser->login();

  mduser->subscribe();
   
}