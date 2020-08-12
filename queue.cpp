// Single direction, linear, linked list class
template <class data_type>
class Queue
{
    private:
        LinkedList<data_type> queue;
        int size = 0;

    public:
        Queue() {}

        void push(data_type v)
        {
            queue.append(v);
            ++size;
        }

        data_type pop()
        {
            if(size == 0) {
                std::cout << "Error: no elements to pop\n";
                exit(0);
            }

            --size;
            return queue.remove(0);
        }

        int getSize() {
            return size;
        }
};
