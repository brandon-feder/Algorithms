class UnicodeChar
{
    private:

    public:
        std::string value;
        UnicodeChar( std::string v)
        {
            value = v;
        }
};

// TODO: Add many more operators
std::ostream &operator<< (std::ostream &txt, UnicodeChar const &t)
{
    return txt << t.value;
}

bool operator> (const UnicodeChar &a, const UnicodeChar &b)
{
    return (a.value.compare(b.value) > 0) ? true : false;
}

bool operator< (const UnicodeChar &a, const UnicodeChar &b)
{
    return (a.value.compare(b.value) < 0) ? true : false;
}

bool operator<= (const UnicodeChar &a, const UnicodeChar &b)
{
    return (a.value.compare(b.value) <= 0) ? true : false;
}

bool operator>= (const UnicodeChar &a, const UnicodeChar &b)
{
    return (a.value.compare(b.value) >= 0) ? true : false;
}

bool operator== (const UnicodeChar &a, const UnicodeChar &b)
{
    return (a.value.compare(b.value) == 0) ? true : false;
}

bool operator!= (const UnicodeChar &a, const UnicodeChar &b)
{
    return (a.value.compare(b.value) != 0) ? true : false;
}
