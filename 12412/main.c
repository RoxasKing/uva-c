#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double EPS = 1e-5;

struct StuStruct;
typedef struct StuStruct Student;

struct StuStruct {
    char *sid, *name;
    int cid, c, m, e, p;
    Student *prev, *next;
};

Student* makeStudent(char* sid, char* name, int cid, int c, int m, int e, int p) {
    Student* out = malloc(sizeof(Student));
    out->sid = malloc(sizeof(char) * 11);
    out->name = malloc(sizeof(char) * 11);
    strcpy(out->sid, sid);
    strcpy(out->name, name);
    out->cid = cid, out->c = c, out->m = m, out->e = e, out->p = p;
    out->prev = NULL, out->next = NULL;
    return out;
}

Student* defaultStudent() { return makeStudent("1111111111", "Default", -1, -1, -1, -1, -1); }

Student *head, *tail;

void pushToTail(Student* stu) {
    stu->prev = tail->prev;
    tail->prev->next = stu;
    stu->next = tail;
    tail->prev = stu;
}

void printWelcome();
void printChoose1();
void printChoose2or3();
void printChoose4();
void printChoose5();
void addStudent();
void removeStudent();
void queryStudent();
void showStatistics();

int main() {
    head = defaultStudent(), tail = defaultStudent();
    head->next = tail;
    tail->prev = head;

    int op;
    printWelcome();
    while (scanf("%d", &op) == 1 && op) {
        switch (op) {
            case 1:
                printChoose1();
                addStudent();
                break;
            case 2:
                printChoose2or3();
                removeStudent();
                break;
            case 3:
                printChoose2or3();
                queryStudent();
                break;
            case 4:
                printChoose4();
                break;
            case 5:
                printChoose5();
                showStatistics();
                break;
        }
        printWelcome();
    }

    return 0;
}

void printWelcome() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n\n");
}

void printChoose1() { printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n"); }
void printChoose2or3() { printf("Please enter SID or name. Enter 0 to finish.\n"); }
void printChoose4() { printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n"); }
void printChoose5() { printf("Please enter class ID, 0 for the whole statistics.\n"); }

void addStudent() {
    char sid[11], name[11];
    int cid, c, m, e, p;
    while (scanf("%s", sid) == 1 && strcmp(sid, "0")) {
        scanf("%d%s%d%d%d%d", &cid, name, &c, &m, &e, &p);
        int duplicate = 0;
        Student* ptr = head->next;
        while (ptr != tail) {
            if (strcmp(ptr->sid, sid) == 0) {
                duplicate = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (duplicate) {
            printf("Duplicated SID.\n");
        } else {
            Student* stu = makeStudent(sid, name, cid, c, m, e, p);
            pushToTail(stu);
        }
        printChoose1();
    }
}

void removeStudent() {
    char buf[11];
    while (scanf("%s", buf) == 1 && strcmp(buf, "0")) {
        int cnt = 0;
        Student* ptr = head->next;
        while (ptr != tail) {
            if (strcmp(ptr->sid, buf) == 0 || strcmp(ptr->name, buf) == 0) {
                Student* next = ptr->next;
                Student* stu = ptr;
                stu->prev->next = stu->next;
                stu->next->prev = stu->prev;
                free(stu);
                ptr = next;
                cnt++;
            } else {
                ptr = ptr->next;
            }
        }
        printf("%d student(s) removed.\n", cnt);
        printChoose2or3();
    }
}

int getScore(Student* stu) { return stu->c + stu->e + stu->m + stu->p; }

int rank(int score) {
    int out = 1;
    Student* ptr = head->next;
    while (ptr != tail) {
        if (getScore(ptr) > score) out++;
        ptr = ptr->next;
    }
    return out;
}

void queryStudent() {
    char buf[11];
    while (scanf("%s", buf) == 1 && strcmp(buf, "0")) {
        Student* ptr = head->next;
        while (ptr != tail) {
            if (strcmp(ptr->sid, buf) == 0 || strcmp(ptr->name, buf) == 0) {
                int score = getScore(ptr);
                printf("%d %s %d %s %d %d %d %d %d %.2lf\n", rank(score), ptr->sid, ptr->cid, ptr->name, ptr->c, ptr->m, ptr->e, ptr->p, score, ((double)score / (double)4) + EPS);
            }
            ptr = ptr->next;
        }
        printChoose2or3();
    }
}

void showStatistics() {
    int cid = 0;
    scanf("%d", &cid);
    int csum = 0, msum = 0, esum = 0, psum = 0;
    int cpss = 0, mpss = 0, epss = 0, ppss = 0;
    int cfai = 0, mfai = 0, efai = 0, pfai = 0;
    int pall = 0, three = 0, two = 0, one = 0, fall = 0;
    Student* ptr = head->next;
    while (ptr != tail) {
        if (cid == 0 || ptr->cid == cid) {
            int cnt = 0;
            csum += ptr->c;
            msum += ptr->m;
            esum += ptr->e;
            psum += ptr->p;
            ptr->c >= 60 ? (cpss++, cnt++) : cfai++;
            ptr->m >= 60 ? (mpss++, cnt++) : mfai++;
            ptr->e >= 60 ? (epss++, cnt++) : efai++;
            ptr->p >= 60 ? (ppss++, cnt++) : pfai++;
            if (cnt == 0) fall++;
            if (cnt >= 1) one++;
            if (cnt >= 2) two++;
            if (cnt >= 3) three++;
            if (cnt == 4) pall++;
        }
        ptr = ptr->next;
    }
    printf("Chinese\n");
    printf("Average Score: %.2lf\n", ((double)csum / (double)(cpss + cfai)) + EPS);
    printf("Number of passed students: %d\n", cpss);
    printf("Number of failed students: %d\n\n", cfai);
    printf("Mathematics\n");
    printf("Average Score: %.2lf\n", ((double)msum / (double)(mpss + mfai)) + EPS);
    printf("Number of passed students: %d\n", mpss);
    printf("Number of failed students: %d\n\n", mfai);
    printf("English\n");
    printf("Average Score: %.2lf\n", ((double)esum / (double)(epss + efai)) + EPS);
    printf("Number of passed students: %d\n", epss);
    printf("Number of failed students: %d\n\n", efai);
    printf("Programming\n");
    printf("Average Score: %.2lf\n", ((double)psum / (double)(ppss + pfai)) + EPS);
    printf("Number of passed students: %d\n", ppss);
    printf("Number of failed students: %d\n\n", pfai);
    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n", pall);
    printf("Number of students who passed 3 or more subjects: %d\n", three);
    printf("Number of students who passed 2 or more subjects: %d\n", two);
    printf("Number of students who passed 1 or more subjects: %d\n", one);
    printf("Number of students who failed all subjects: %d\n\n", fall);
}
