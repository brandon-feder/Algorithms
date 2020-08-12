template <class data_type>

class DblLinkedList
{
    private:
        struct Node
        {
            Node *next  = NULL; // Contains the next node in the list
            Node *prev  = NULL; // Contains the next node in the list
            data_type value; // The value contained by the current node
        };

        Node *root = NULL; // First element of the Linked List
        int size = 0; // The number of element in the list

        void swap(int a, int b)
        {

        }

        Node *getNode(int index)
        {
            Node *currentNode = root;

            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            return currentNode;
        }

    public:
        // Returns the size of the new list
        void append(data_type v)
        {


            ++size; // Increment the size
        }

        // Appends the new element to the front of the list
        void append_front(data_type v)
        {

            // Increment size
            ++size;

        }

        data_type get(int index)
        {
            if(index >= size || index < 0)
            {
                std::cout << "Error: Invalid index in function get()\n";
                exit(0);
            }

            // Iterate over the list until index index
            Node *currentNode = root;
            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            // return the value of that list node
            return currentNode->value;
        }

        void set(int index, data_type val)
        {
            if(index >= size || index < 0)
            {
                std::cout << "Error: Invalid index in function set()\n";
                exit(0);
            }

            Node* currentNode = root;

            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            currentNode->value = val;
        }

        int getSize()
        {
            return size;
        }

        data_type remove(int index)
        {


            --size;
            // return returnValue;
        }


        // Implementation of bubble sort
        // Note* I could make this more efficient by making the swap function return the next node to swap instead of finding a and b from scratch everyime
        // But that takes away from the elegance of the solution and is pointless as bubble sort is not efficient in the first place which is why I did not
        // do that. Its just a pointer demonstration instead of a practical solution
        void bubbleSort()
        {
            if(size == 0)
                return;

            bool isDone = false; // Whether all the nodes are sorted

            while(!isDone)
            {
                isDone = true;

                // For every pair of nodes
                for(int i = 0; i < size-1; i++)
                {
                    data_type a = getNode(i)->value;
                    data_type b = getNode(i+1)->value;

                    // If the first of the pair is < than the second, swap
                    if(a > b)
                    {
                        isDone = false;
                        swap(i, i+1);
                    }
                }
            }
        }
};
