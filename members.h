#ifndef MEMBERS_H           // Prevent a duplicate header loading
#define MEMBERS_H           // Define header guard name

// Maximum number of members
#define MAX_MEMBERS 200

// Maximum member ID length
#define MEMBER_ID_SIZE 20

// Maximum number of characters for member text fields
#define MEMBER_TEXT_SIZE 80

// Member structure definition
typedef struct {

    // Store the member's ID
    char id[MEMBER_ID_SIZE];

    // Store the member's full name
    char name[MEMBER_TEXT_SIZE];

    // Store the member's phone number
    char phone[30];

} Member; // End the member structure

// External member array declaration
extern Member members[MAX_MEMBERS];

// External member counter declaration
extern int memberCount;

// Register member function prototype
void registerMember(void);

// View members function prototype
void viewMembers(void);

// Search member ID prototype
int findMemberIndexById(const char *memberId);

#endif // End header guard
