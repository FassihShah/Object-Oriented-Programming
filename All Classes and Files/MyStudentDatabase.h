#ifndef STUDENT_DATA
#define STUDENT_DATA
int findIndex(int rollNo, const char file[]);
void deleteRecord(const char file[], int index);
void deleteRecordApp(const char file[]);
void updateRecord(const char file[]);
void addRecord(const char file[]);
void studentDatabaseApp(const char file[]);
#endif