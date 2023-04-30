#include "./pr1/SSI-pr1.h"
#include "./pr2/original/main.h"
#include "./pr3/main.h"
#include "./pr4/main.h"
#include "./pr5/original/main.h"
#include "./pr6/main.h"
#include "./pr7/org/main.h"
#include "./pr8/main.h"
#include "./pr9/main.h"
#include "./pr10/main.h"


int main () {


  std::cout << "Bienvenido al menu de practicas de SSI" << std::endl;

  std::cout << "Seleccione la practica que desea ejecutar:" << std::endl;

  std::cout << "1. Practica 1" << std::endl;
  std::cout << "2. Practica 2" << std::endl;
  std::cout << "3. Practica 3" << std::endl;
  std::cout << "4. Practica 4" << std::endl;
  std::cout << "5. Practica 5" << std::endl;
  std::cout << "6. Practica 6" << std::endl;
  std::cout << "7. Practica 7" << std::endl;
  std::cout << "8. Practica 8" << std::endl;
  std::cout << "9. Practica 9" << std::endl;
  std::cout << "10. Practica 10" << std::endl;

  std::string original_text;
  int practica;
  std::getline(std::cin, original_text);
  
  practica = std::stoi(original_text);

  switch ( practica ) {
    case 1:
      std::cout << "Ha seleccionado la practica 1" << std::endl;
      pr1();
      break;
    case 2:
      std::cout << "Ha seleccionado la practica 2" << std::endl;
      pr2();
      break;
    case 3:
      std::cout << "Ha seleccionado la practica 3" << std::endl;
      pr3();
      break;
    case 4:
      std::cout << "Ha seleccionado la practica 4" << std::endl;
      pr4();
      break;
    case 5:
      std::cout << "Ha seleccionado la practica 5" << std::endl;
      pr5();
      break;
    case 6:
      std::cout << "Ha seleccionado la practica 6" << std::endl;
      pr6();
      break;
    case 7:
      std::cout << "Ha seleccionado la practica 7" << std::endl;
      pr7();
      break;
    case 8:
      std::cout << "Ha seleccionado la practica 8" << std::endl;
      pr8();
      break;
    case 9:
      std::cout << "Ha seleccionado la practica 9" << std::endl;
      pr9();
      break;
    case 10:
      std::cout << "Ha seleccionado la practica 10" << std::endl;
      pr10();
      break;
    default:
      std::cout << "Ha seleccionado una practica no valida" << std::endl;
      break;
  }





}