#include <iostream>
#include "array.h"
#include "figure.h"

static void pechat_menu()
{
    std::cout << "\nMenu:\n";
    std::cout << "1 - add figure\n";
    std::cout << "2 - print all\n";
    std::cout << "3 - total area\n";
    std::cout << "4 - delete by index\n";
    std::cout << "0 - exit\n";
    std::cout << " Comanda: ";
}

static void pechat_tipov()
{
    std::cout << "Figure type:\n";
    std::cout << "1 - Rectangle\n";
    std::cout << "2 - Trapezoid\n";
    std::cout << "3 - Rhombus\n";
    std::cout << "type: ";
}

int main()
{
    Array arr;

    int cmd = -1;

    while (true)
    {
        pechat_menu();

        if (!(std::cin >> cmd))
        {
            break;
        }

        if (cmd == 0)
        {
            break;
        }

        if (cmd == 1)
        {
            int tip = 0;

            pechat_tipov();
            std::cin >> tip;

            Figure* f = sozdat_figuru_po_tipu(tip);
            if (f == nullptr)
            {
                std::cout << "Unknown type\n";
                continue;
            }

            std::cout << "Vvedite koordinati 4 tochek (x y) po chasovoy ili protiv chasovoy strelki:\n";
            std::cout << "Primer vvoda dvya romba: -1 0  0 -1  1 0  0 1\n";

            std::cin >> *f;

            arr.push_back(f);

            std::cout << "Figura dobavlena\n";
        }
        else if (cmd == 2)
        {
            if (arr.size() == 0)
            {
                std::cout << "Array pustoy\n";
            }
            else
            {
                arr.print_all(std::cout);
            }
        }
        else if (cmd == 3)
        {
            double s = arr.total_area();
            std::cout << "Total area = " << s << "\n";
        }
        else if (cmd == 4)
        {
            std::size_t index = 0;

            std::cout << "index: ";
            std::cin >> index;

            bool ok = arr.remove(index);
            if (ok)
            {
                std::cout << "Deleted\n";
            }
            else
            {
                std::cout << "Bad index\n";
            }
        }
        else
        {
            std::cout << "Wrong command\n";
        }
    }

    return 0;
}
