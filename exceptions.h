
#ifndef HW4_EXCEPTIONS_H
#define HW4_EXCEPTIONS_H

#include <stdexcept>

//basisklasse für alle exceptions
class GameException : public std::runtime_error{
public:
    explicit GameException(const std::string &message) : std::runtime_error(message) {
    }
};

//basisklasse für inventory exceptions
class InventoryException : public GameException{
public:
    explicit InventoryException(const std::string &message) : GameException(message) {}
};


class InvalidArgumentException : public GameException{
public:
    explicit InvalidArgumentException(const std::string &message) : GameException(message) {}
};



class InventoryInvalidSlotException : public InventoryException{
public:
    InventoryInvalidSlotException() : InventoryException("Invalid slot!") {}
};

class InventoryEmptySlotException : public InventoryException{
public:
    InventoryEmptySlotException() : InventoryException("Empty slot!") {}
};


class InventoryFullException : public InventoryException{
public:
    InventoryFullException() : InventoryException("Inventory is full!") {}
};





#endif //HW4_EXCEPTIONS_H
