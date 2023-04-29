#include "FruitController.h"

Controller::FruitController::FruitController(const string &fileName) : fruitRepository(fileName){
    fruits = fruitRepository.getAll();
}