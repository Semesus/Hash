#include <iostream>
//#include "HashTable.h"
#include "Index.h"
#include <assert.h>

std::shared_ptr<std::string> str1 = std::make_shared<std::string>("alpha");
std::shared_ptr<std::string> str2 = std::make_shared<std::string>("bravo");
std::shared_ptr<std::string> str3 = std::make_shared<std::string>("charlie");
std::shared_ptr<std::string> str4 = std::make_shared<std::string>("delta");
std::shared_ptr<std::string> str5 = std::make_shared<std::string>("echo");
std::shared_ptr<std::string> str6 = std::make_shared<std::string>("foxtrot");
std::shared_ptr<std::string> str7 = std::make_shared<std::string>("golf");
std::shared_ptr<std::string> str8 = std::make_shared<std::string>("hotel");
std::shared_ptr<std::string> str9 = std::make_shared<std::string>("india");
std::shared_ptr<std::string> str10 = std::make_shared<std::string>("juliet");
std::shared_ptr<std::string> str11 = std::make_shared<std::string>("kilo");
std::shared_ptr<std::string> str12 = std::make_shared<std::string>("lima");
std::shared_ptr<std::string> str13 = std::make_shared<std::string>("mike");

void basicTest() {
    HashTable ht(6);
    ht.printTable();
    std::cout << "insert 1" << std::endl;
    ht.Insert(str1, 1);
    ht.printTable();
    std::cout << "insert 3" << std::endl;
    ht.Insert(str3, 3);
    ht.printTable();
    std::cout << "insert 5" << std::endl;
    ht.Insert(str5, 5);
    ht.printTable();
    std::cout << "insert 7" << std::endl;
    ht.Insert(str7, 7);
    ht.printTable();
    ht.Insert(str9, 9);
    std::cout << "insert 9" << std::endl;
    ht.printTable();
    std::cout << "insert 11" << std::endl;
    ht.Insert(str11, 11);
    ht.printTable();
    std::cout << "insert 2" << std::endl;
    ht.Insert(str2, 2);
    ht.printTable();
    std::cout << "insert 4" << std::endl;
    ht.Insert(str4, 4);
    ht.printTable();
    std::cout << "insert 6" << std::endl;
    ht.Insert(str6, 6);
    ht.printTable();
    std::cout << "insert 8" << std::endl;
    ht.Insert(str8, 8);
    ht.printTable();
    std::cout << "insert 10" << std::endl;
    ht.Insert(str10, 10);
    //ht.Insert(str12, 12);
    ht.Remove(str7);
    ht.Remove(str13);

    ht.printTable();
    ht.printHistogram();
    //std::cout << ht.getLength() << std::endl;
}

void test1() {
    Index ind;
    ind.Insert(str1, 1);
    ind.Insert(str3, 3);
    ind.Insert(str5, 5);
    ind.printTable();
    ind.Remove(str3);
    ind.printTable();
    ind.printHistogram();
    assert(ind.Find(str5) == 5);
}

int main() {
    //basicTest();
    test1();
    return 0;
}
