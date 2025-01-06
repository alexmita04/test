#include <exception>
#include <string>
#include <iostream>

class JocException : public std::exception
{
protected:
    std::string mesaj;

public:
    explicit JocException(const std::string &mesaj_) : mesaj(mesaj_) {}
    const char *what() const noexcept override { return mesaj.c_str(); }
};

class FisierInaccesibilException : public JocException
{
public:
    explicit FisierInaccesibilException(const std::string &nume_fisier)
        : JocException("Eroare: Fișierul \"" + nume_fisier + "\" nu poate fi accesat.") {}
};

class IndexInvalidException : public JocException
{
public:
    explicit IndexInvalidException(size_t index)
        : JocException("Eroare: Index invalid \"" + std::to_string(index) + "\".") {}
};

class JucatorInvalidException : public JocException
{
public:
    explicit JucatorInvalidException(const std::string &nume_jucator)
        : JocException("Eroare: Jucătorul \"" + nume_jucator + "\" nu este valid pentru această acțiune.") {}
};