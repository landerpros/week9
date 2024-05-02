#include <iostream>
#include <string>

using namespace std;

// Dinh nghia
struct Student {
    string id;
    string name;
    string gioiTinh;
    string ngaySinh;
    string diaChi;
    string lop;
    string khoa;
    Student* next;
};

// Them sinh vien - Tao danh sach ban dau
void addStudent(Student*& head, string id, string name, string gioiTinh, string ngaySinh, string diaChi, string lop, string khoa) {
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->name = name;
    newStudent->gioiTinh = gioiTinh;
    newStudent->ngaySinh = ngaySinh;
    newStudent->diaChi = diaChi;
    newStudent->lop = lop;
    newStudent->khoa = khoa;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// Sap xep
void sortStudent(Student*& head) {
    Student* current = head;
    Student* index = nullptr;

    if (current == nullptr) {
        return;
    } else {
        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->id > index->id) {
                    swap(current->id, index->id);
                    swap(current->name, index->name);
                    swap(current->gioiTinh, index->gioiTinh);
                    swap(current->ngaySinh, index->ngaySinh);
                    swap(current->diaChi, index->diaChi);
                    swap(current->lop, index->lop);
                    swap(current->khoa, index->khoa);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// In danh sach sinh vien
void printStudent(Student* head) {
    Student* current = head;

    if (current == nullptr) {
        cout << "Empty" << endl;
    } else {
        cout << "In danh sach sinh vien:" << endl;
        while (current != nullptr) {
            cout << "MSSV: " << current->id << ", Ho ten: " << current->name << ", GioiTinh: " << current->gioiTinh << ", Ngay sinh: " << current->ngaySinh << ", Dia chi: " << current->diaChi << ", Lop: " << current->lop << ", Khoa: " << current->khoa << endl;
            current = current->next;
        }
    }
}

// Them sinh vien vao danh sach da sap xep
void addStudentPromax(Student*& head, string id, string name, string gioiTinh, string ngaySinh, string diaChi, string lop, string khoa) {
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->name = name;
    newStudent->gioiTinh = gioiTinh;
    newStudent->ngaySinh = ngaySinh;
    newStudent->diaChi = diaChi;
    newStudent->lop = lop;
    newStudent->khoa = khoa;
    newStudent->next = nullptr;

    if (head == nullptr || head->id > id) {
        newStudent->next = head;
        head = newStudent;
    } else {
        Student* current = head;
        while (current->next!= nullptr && current->next->id < id) {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }
}

// In danh sach cung ngay sinh
void printStudentCungNgaySinh(Student*& head, const string& targetDob) {
    Student *current = head;
    bool found = false;
    cout << "In danh sach cung ngay sinh" << endl;
    while (current != nullptr) {
        if (current->ngaySinh == targetDob) {
            cout << "MSSV: " << current->id << ", Ho ten: " << current->name << ", GioiTinh: " << current->gioiTinh << ", Ngay sinh: " << current->ngaySinh << ", Dia chi: " << current->diaChi << ", Lop: " << current->lop << ", Khoa: " << current->khoa << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Empty" << endl;
    }
}

// Xoa sinh vien cung ngay sinh
void removeStudentCungNgaySinh(Student*& head, const string& targetDob) {
    Student* current = head;
    Student* prev = nullptr;

    while (current != nullptr) {
        if (current->ngaySinh == targetDob) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            Student* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Student* head = nullptr;

    // Add some students to the list
    addStudent(head, "1", "Doc", "Nam", "02/09/2004", "Hanoi", "ETTN", "SET");
    addStudent(head, "2", "Lap", "Nu", "30/04/2004", "Hung Yen", "ETTN", "SET");
    addStudent(head, "4", "Do", "Nu", "02/09/2004", "Hai Duong", "ETTN", "SET");

    // Sort the list of students by student ID
    sortStudent(head);

    // Print the list of students
    printStudent(head);
    
    // Add a new student to the sorted list
    addStudentPromax(head, "3", "Tu", "Nam", "10/08/2004", "Bac Giang", "ETTN", "SET");

    // Print the list of students
    printStudent(head);
    
    printStudentCungNgaySinh(head, "01/01/2000");
    
   removeStudentCungNgaySinh(head, "01/01/2000");
    printStudent(head);
    
    return 0;
}

