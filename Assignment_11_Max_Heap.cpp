#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &heap,int val){
    heap.push_back(val); // Inserting at the end
    int i = heap.size() - 1;
    while(i > 1){
        int parent = i / 2;
        if(heap[parent] < heap[i]){
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            return;
        }
    }
}

void deletion(vector<int>& heap, int index) {
    int n = heap.size();
    heap[index] = heap[n - 1];
    heap.pop_back();
    n--;

    int i = index;

    while(i < n){
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if(leftChild < n && heap[leftChild] > heap[i]){
            swap(heap[leftChild] , heap[i]);
            i = leftChild;
        }
        else if (rightChild < n && heap[rightChild] > heap[i]){
            swap(heap[rightChild] , heap[i]);
            i = rightChild;
        } else {
            return;
        }
    }
}

void display(vector<int> &heap) {
    for (int i = 1; i < heap.size(); i++) {
        cout << heap[i] << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of students" << endl;
    cin >> n;
    vector<int> marks(n + 1);

    cout << "Enter the marks of the students " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> marks[i];
    }

    vector<int> heap;
    heap.push_back(-1); // dummy value at index 0

    for (int i = 1; i <= n; i++) {
        insert(heap, marks[i]);
    }

    cout << "Max Heap: ";
    display(heap);

    deletion(heap,1);
    cout<<"After deleting first node : "<<endl;
    cout << "Max Heap: ";
    display(heap);

    cout << "Minimum Marks : " << heap[heap.size() - 1] << endl;
    cout << "Maximum Marks : " << heap[1] << endl;

    return 0;
}
