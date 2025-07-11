#include "Commando.h"
#include "Item.h"
#include <iostream>

void Commando::addItem(std::unique_ptr<Item> item)
{
    inventory.push_back(std::move(item));
}

const std::vector<std::unique_ptr<Item>> &Commando::getItems() const
{
    return inventory;
}

std::vector<std::unique_ptr<Item>> &Commando::getItems()
{
    return inventory;
}

void Commando::doSpeak()
{
    std::cout << "[Commando] Do boju!\n";
}
