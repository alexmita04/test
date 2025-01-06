#include <iostream>
#include "include/Sportiv.h"
#include "include/Echipa.h"
#include "include/Scor.h"
#include "include/Joc.h"
#include "include/Exceptii.h" // Asigura-te ca include excepțiile personalizate

int main()
{
    try
    {
        // Inițializează jocul cu fișierele de intrare
        Joc joc_actual("echipe.txt", "sportivi_fotbal.txt", "sportivi_box.txt", "sportivi_inot.txt");

        // Pornește jocul
        joc_actual.start_game();
    }
    catch (const JocException &e) // Prinde excepțiile specifice jocului
    {
        std::cerr << "Eroare specifică: " << e.what() << std::endl;
        return 1; // Cod de eroare specific
    }
    catch (const std::exception &e) // Prinde alte excepții din STL
    {
        std::cerr << "Eroare neașteptată: " << e.what() << std::endl;
        return 2; // Cod de eroare generic
    }
    catch (...) // Prinde orice altceva (siguranță suplimentară)
    {
        std::cerr << "Eroare necunoscută a apărut." << std::endl;
        return 3; // Cod de eroare necunoscut
    }

    return 0; // Executare cu succes
}