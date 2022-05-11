#include <iostream>
#include "list.h"

int main()
{
    List<double> list(7, [](const size_t i) { return 1.0 + i; });

    std::cout << "Lista:" << std::endl;
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Dodanie na begin" << std::endl;
    auto it1 = list.begin();
    list.insert(it1, 100.0);
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Dodanie na pozycje 3" << std::endl;
    auto it2 = list.begin();
    it2++;
    ++it2;
    list.insert(it2, 200.0);
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Dodanie na end" << std::endl;
    auto it3 = list.end();
    list.insert(it3, 300.0);
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Dodanie na ostatnim miejscu (czyli jak jest 1,2,3 to ma byc 1,2,-1,3)" << std::endl;
    auto it6 = list.end();
    it6--;
    list.insert(it6, -1);
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Usuwanie pozycji 3" << std::endl;
    auto it4 = list.begin();
    it4++;
    ++it4;
    list.erase(it4);
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Usuwanie begin" << std::endl;
    list.erase(list.begin());
    for (const auto& el : list)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Usuwanie ostatneiego elementu" << std::endl;
    auto it5 = list.end();
    --it5;
    list.erase(it5);
    for (const auto& el : list)
        std::cout << el << " ";

    List<double> list2;
    std::cout << std::endl << std::endl << "Lista2:" << std::endl;
    for (const auto& el : list2)
        std::cout << el << " ";

    auto it21 = list2.begin();
    list2.insert(it21, 50.0);
    std::cout << std::endl << std::endl << "Lista2 pusta, dodanie na begin" << std::endl;
    for (const auto& el : list2)
        std::cout << el << " ";

    List<double> list3;
    std::cout << std::endl << std::endl << "Lista3:" << std::endl;
    for (const auto& el : list3)
        std::cout << el << " ";

    auto it31 = list3.end();
    list3.insert(it31, 50.0);
    std::cout << std::endl << std::endl << "Lista3 pusta, dodanie na end" << std::endl;
    for (const auto& el : list3)
        std::cout << el << " ";

    List<double> list4(5, [](const size_t i) { return 1.0 + i; });
    std::cout << std::endl << std::endl << "Lista4 z dodanym 100 na begin i end:" << std::endl;
    list4.insert(list4.begin(), 100);
    list4.insert(list4.end(), 100);
    for (const auto& el : list4)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista4 pop_back 3 razy" << std::endl;
    list4.pop_back();
    list4.pop_back();
    list4.pop_back();
    for (const auto& el : list4)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista4 pop_back az do pustego" << std::endl;
    list4.pop_back();
    list4.pop_back();
    list4.pop_back();
    list4.pop_back();
    for (const auto& el : list4)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista4 push_back 4 elementow do pustej listy" << std::endl;
    list4.insert(list4.end(), 1000);
    list4.insert(list4.begin(), 100);
    list4.insert(list4.end(), 10000);
    list4.push_back(100000);
    for (const auto& el : list4)
        std::cout << el << " ";

    List<double> list5(1, [](const size_t i) { return 1.0 + i; });
    std::cout << std::endl << std::endl << "Lista5:" << std::endl;
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 ma 1 element i wtedy erase" << std::endl;
    list5.erase(list5.begin());
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 push_back" << std::endl;
    list5.push_back(100);
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 pop_front" << std::endl;
    list5.pop_front();
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 push_back" << std::endl;
    list5.push_back(100);
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 pop_back" << std::endl;
    list5.pop_back();
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 insert end gdy pusta lista" << std::endl;
    list5.insert(list5.end(), 100);
    for (const auto& el : list5)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista5 push_front" << std::endl;
    list5.push_front(-100);
    for (const auto& el : list5)
        std::cout << el << " ";

    List<double> list6;
    std::cout << std::endl << std::endl << "Lista6:" << std::endl;
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 push_front na pustej liscie" << std::endl;
    list6.push_front(100);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 push_back" << std::endl;
    list6.push_back(1000);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 push_front" << std::endl;
    list6.push_front(10);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 clear" << std::endl;
    list6.clear();
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 push_back" << std::endl;
    list6.push_back(1000);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 clear" << std::endl;
    list6.clear();
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 push_front" << std::endl;
    list6.push_front(10);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 clear" << std::endl;
    list6.clear();
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 insert end" << std::endl;
    list6.insert(list6.end(), 100);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 insert end" << std::endl;
    list6.insert(list6.end(), 1000);
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 clear" << std::endl;
    list6.clear();
    for (const auto& el : list6)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista6 size" << std::endl;
    std::cout<<list6.size();

    List<double> list7(8, [](const size_t i) { return 1.0 + i; });
    std::cout << std::endl << std::endl << "Lista7:" << std::endl;
    for (const auto& el : list7)
        std::cout << el << " ";

    auto it7 = list7.find(1);
    auto it8 = list7.find(5);
    auto it9 = list7.find(8);
    auto it10 = list7.find(100);
    std::cout << std::endl << std::endl << "Lista7 po usunieciu 1,5 i 8" << std::endl;
    list7.erase(it7);
    list7.erase(it8);
    list7.erase(it9);
    list7.erase(it10);
    for (const auto& el : list7)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista7 wstawienie w miejscu w ktorym find nie znalazlo elementu" << std::endl;
    list7.insert(it10, 100);
    for (const auto& el : list7)
        std::cout << el << " ";

    List<double> list8(7, [](const size_t i) { return 1.0 + i; });
    std::cout << std::endl << std::endl << "Lista8:" << std::endl;
    for (const auto& el : list8)
        std::cout << el << " ";

    List<double> list9(list8);
    std::cout << std::endl << std::endl << "Lista9: (kopia 8)" << std::endl;
    for (const auto& el : list9)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista8 zeby sprawdzic czy dziala po kopi" << std::endl;
    for (const auto& el : list8)
        std::cout << el << " ";

    List<double> list10(std::move(list8));
    std::cout << std::endl << std::endl << "Lista10: (przeniesienie 8)" << std::endl;
    for (const auto& el : list10)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista8 zeby sprawdzic czy dziala po przenieseniu" << std::endl;
    for (const auto& el : list8)
        std::cout << el << " ";

    List<double> list11 = { 2,5,7.6,5,5.9 };
    std::cout << std::endl << std::endl << "Lista11: (za pomoca il)" << std::endl;
    for (const auto& el : list11)
        std::cout << el << " ";

    List<double> list12(6, [](const size_t i) { return 100.0 + i; });
    std::cout << std::endl << std::endl << "Lista12:" << std::endl;
    for (const auto& el : list12)
        std::cout << el << " ";
    
    List<double> list13(2, [](const size_t i) { return 1.0 + i; });
    std::cout << std::endl << std::endl << "Lista13:" << std::endl;
    for (const auto& el : list13)
        std::cout << el << " ";

    List<double> list14;
    std::cout << std::endl << std::endl << "Lista14:" << std::endl;
    for (const auto& el : list14)
        std::cout << el << " ";

    list13 = list12;
    std::cout << std::endl << std::endl << "Lista13 operator = list12" << std::endl;
    for (const auto& el : list13)
        std::cout << el << " ";

    list13 = list14;
    std::cout << std::endl << std::endl << "Lista13 operator = list14" << std::endl;
    for (const auto& el : list13)
        std::cout << el << " ";

    list14 = list12;
    std::cout << std::endl << std::endl << "Lista14 operator = list12" << std::endl;
    for (const auto& el : list14)
        std::cout << el << " ";

    list14 = std::move(list13);
    std::cout << std::endl << std::endl << "Lista14 operator std::move(list13)" << std::endl;
    for (const auto& el : list14)
        std::cout << el << " ";

    list14 = std::move(list12);
    std::cout << std::endl << std::endl << "Lista14 operator std::move(list12)" << std::endl;
    for (const auto& el : list14)
        std::cout << el << " ";

    std::cout << std::endl << std::endl << "Lista12 zeby sprawdzic czy dziala po przenieseniu" << std::endl;
    for (const auto& el : list12)
        std::cout << el << " ";

    List<double> list15(5, [](const size_t i) { return 1.0 + i; });
    std::cout << std::endl << std::endl << "Lista15:" << std::endl;
    for (const auto& el : list15)
        std::cout << el << " ";

    list15.clear();
    std::cout << std::endl << std::endl << "Lista15 clear" << std::endl;
    for (const auto& el : list15)
        std::cout << el << " ";

    list15.push_back(500);
    std::cout << std::endl << std::endl << "Lista15 push_back" << std::endl;
    for (const auto& el : list15)
        std::cout << el << " ";
}