// Consider a special family of Engineers and Doctors with following rules :

// Everybody has two children.
// First child of an Engineer is an Engineer and second child is a Doctor.
// First child of an Doctor is Doctor and second child is an Engineer.
// All generations of Doctors and Engineers start with Engineer.
// The first few levels of the family tree are shown below :

class Solution {
public:
    string profession(int level, int pos) {
        if (level == 1)
            return "Engineer";

        string parent = profession(level - 1, (pos + 1) / 2);

        if (pos % 2 == 1) { // left child
            return parent;
        } else { // right child
            return parent == "Engineer" ? "Doctor" : "Engineer";
        }
    }
}; 