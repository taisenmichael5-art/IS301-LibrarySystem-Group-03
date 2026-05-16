#include <stdio.h>          // Standard input output library
#include <string.h>         // String handling functions
#include "members.h"        // Member structure declarations
#include "filehandling.h"   // File saving function declarations

Member members[MAX_MEMBERS]; // Array storing all members
int memberCount = 0;         // Total registered members

// Register new library member
void registerMember(void) {

    Member newMember; // Temporary member storage

    // Check member storage capacity
    if (memberCount >= MAX_MEMBERS) {

        // Display storage full message
        printf("\nMember storage is full. Cannot register another member.\n");

        // Exit current function
        return;
    }

    // Display the registration heading
    printf("\nRegister New Member\n");

    // Read the member ID input
    readLine("Member ID: ", newMember.id, sizeof(newMember.id));

    // Check if there is a duplicate member ID
    if (findMemberIndexById(newMember.id) != -1) {

        // Display a duplicate ID warning
        printf("A member with this ID already exists.\n");

        // Exit current function
        return;
    }

    // Read the full name of the member
    readLine("Full name: ", newMember.name, sizeof(newMember.name));

    // Read the  phone number of the member
    readLine("Phone number: ", newMember.phone, sizeof(newMember.phone));

    // Store the member into array
    members[memberCount] = newMember;

    // Increase the member counter
    memberCount++;

    // Save members into file
    saveMembersToFile("members.txt");

    // Display successful registration message
    printf("Member registered and saved successfully.\n");
}

// Display all registered members
void viewMembers(void) {

    int i; // Loop counter variable

    // Check if members exist
    if (memberCount == 0) {

        // Display empty member message
        printf("\nNo members found. Register members first or check members.txt.\n");

        // Exit current function
        return;
    }

    // Display table headings
    printf("\n%-12s %-30s %-20s\n", "Member ID", "Name", "Phone");

    // Display separator line
    printf("----------------------------------------------------------------\n");

    // Loop through member records
    for (i = 0; i < memberCount; i++) {

        // Display member information
        printf("%-12s %-30s %-20s\n",
               members[i].id,
               members[i].name,
               members[i].phone);
    }
}

// Search member using ID
int findMemberIndexById(const char *memberId) {

    int i; // Loop counter variable

    // Loop through member array
    for (i = 0; i < memberCount; i++) {

        // Compare the member IDs
        if (strcmp(members[i].id, memberId) == 0) {

            // Return matching index
            return i;
        }
    }

    // Return not found value
    return -1;
}
