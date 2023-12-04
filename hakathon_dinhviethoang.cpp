#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    char birthday[50];
    char address[50];
    int status;
};

void printStudent(struct SinhVien student) {
    printf("ID sinh vien: %d\n", student.id);
    printf("Ten: %s\n", student.name);
    printf("Ngay sinh: %s\n", student.birthday);
    printf("Dia chi: %s\n", student.address);
    printf("Trang thai: %d\n", student.status);
    printf("--------------------------\n");
}

void printStudentList(struct SinhVien arr[100], int size) {
    for (int i = 0; i < size; i++) {
        printStudent(arr[i]);
    }
}

void addStudent(struct SinhVien studentList[100], int *currentStudent) {
    struct SinhVien newStudent;
    printf("Nhap thong tin sinh vien moi:\n");
    printf("ID: ");
    scanf("%d", &newStudent.id);
    printf("Ten: ");
    scanf("%s", newStudent.name);
    printf("Ngay sinh: ");
    scanf("%s", newStudent.birthday);
    printf("Dia chi: ");
    scanf("%s", newStudent.address);
    printf("Status: ");
    scanf("%d", &newStudent.status);

    studentList[*currentStudent] = newStudent;
    (*currentStudent)++;
}

void updateStudent(struct SinhVien studentList[100], int currentStudent) {
    char searchName[50];
    int found = 0;

    printf("Nhap ten sinh vien can cap nhat: ");
    scanf("%s", searchName);

    for (int i = 0; i < currentStudent; ++i) {
        if (strcmp(studentList[i].name, searchName) == 0) {
            found = 1;
            printf("Nhap thong tin moi cho sinh vien %s:\n", searchName);
            printf("ID: ");
            scanf("%d", &studentList[i].id);
            printf("Ngay sinh: ");
            scanf("%s", studentList[i].birthday);
            printf("Dia chi: ");
            scanf("%s", studentList[i].address);
            printf("Status: ");
            scanf("%d", &studentList[i].status);
            printf("Da cap nhat thong tin cho sinh vien %s.\n", searchName);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien %s.\n", searchName);
    }
}

void deleteStudent(struct SinhVien studentList[100], int *currentStudent) {
    char searchName[50];
    int found = 0;

    printf("Nhap ten sinh vien can xoa: ");
    scanf("%s", searchName);

    for (int i = 0; i < *currentStudent; ++i) {
        if (strcmp(studentList[i].name, searchName) == 0) {
            found = 1;
            for (int j = i; j < *currentStudent - 1; ++j) {
                studentList[j] = studentList[j + 1];
            }
            (*currentStudent)--;
            printf("Da xoa sinh vien %s.\n", searchName);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien %s.\n", searchName);
    }
}
void bubbleSort(struct SinhVien studentList[100], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (studentList[j].id > studentList[j + 1].id) {
                // swap the elements if they are in the wrong order
                struct SinhVien temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct SinhVien sinhvien1 = {1, "hoang", "16/8/2005", "ton duc thang", 1};
    struct SinhVien sinhvien2 = {2, "my", "6/6/2005", "khuong trung", 2};

    struct SinhVien studentList[100];
    studentList[0] = sinhvien1;
    studentList[1] = sinhvien2;

    int currentStudent = 2;
    int choice;

    do {
        printf("**********MENU**********\n");
        printf("1. In toan bo danh sach sinh vien\n");
        printf("2. Them moi sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Sap xep danh sach sinh vien\n");
        printf("6. Tim kiem theo ten\n");
        printf("7. Tim kiem theo status\n");
        printf("8. Thoat\n");
        printf("************************\n");
        printf("Chon chuc nang (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudentList(studentList, currentStudent);
                break;
            case 2:
                addStudent(studentList, &currentStudent);
                break;
            case 3:
                updateStudent(studentList, currentStudent);
                break;
            case 4:
                deleteStudent(studentList, &currentStudent);
                break;
            case 5:
			bubbleSort(studentList, currentStudent);
                printf("Danh sach sinh vien da sap xep theo ID:\n");
                printStudentList(studentList, currentStudent);
                break; 
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Chon sai, vui long chon lai.\n");
        }
    } while(1==1); 

    return 0;
}

