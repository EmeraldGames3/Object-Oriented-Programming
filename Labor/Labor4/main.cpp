#include "Tests/TestAll.h"
#include "UI/UI.h"
#include "Repository/Repository.h"

using namespace UI;

int main() {
    testAll();
//    UserInterface::run();

    Repository::FruitRepository fruitRepository(Repository::dataBase);
}