// Single direction, linear, linked list class
template <class data_type>
class Stack
{
    private:
        LinkedList<data_type> stack;

    public:
        int size = 0;
        Stack() {}

        void push(data_type v)
        {
            ++size;
            stack.append(v);
        }

        data_type pop()
        {
            if(size == 0) {
                std::cout << "Error: no elements to pop\n";
                exit(0);
            }
            --size;
            return stack.remove(stack.getSize()-1);
        }

        int getSize()
        {
            return size;
        }
};
