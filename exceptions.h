
#ifndef HW4_EXCEPTIONS_H
#define HW4_EXCEPTIONS_H

#include <stdexcept>

//basisklasse für alle exceptions
class GameException : public std::runtime_error{
public:
    using std::runtime_error::runtime_error;
};

//basisklasse für inventory exceptions
class InventoryException : public GameException{
public:
    using GameException::GameException;
};


class InvalidArgumentException : public GameException{
public:
    using GameException::GameException;
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
