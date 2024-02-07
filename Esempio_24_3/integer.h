#ifndef INTEGER_H
#   define INTEGER_H

class integer
{
    public:
        int value;

        integer (int i_value) : value(i_value)
        {
            /* Do nothing */
        }

        integer 
        operator * (const integer in2)
        {
            integer result(value * in2.value);
            return (result);
        }
};

#endif /* INTEGER_H */