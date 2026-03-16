#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Open syslog with LOG_USER facility
    openlog("writer", LOG_PID, LOG_USER);

    // Check for correct number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments are required: <file path> <string>");
        fprintf(stderr, "Error: Two arguments are required: <file path> <string>\n");
        closelog();
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Log the write operation
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Open file for writing (truncate if exists)
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error: Could not open file '%s' for writing", writefile);
        fprintf(stderr, "Error: Could not open file '%s' for writing.\n", writefile);
        closelog();
        exit(1);
    }

    // Write the string to the file
    if (fprintf(fp, "%s\n", writestr) < 0) {
        syslog(LOG_ERR, "Error: Could not write to file '%s'", writefile);
        fprintf(stderr, "Error: Could not write to file '%s'.\n", writefile);
        fclose(fp);
        closelog();
        exit(1);
    }

    // Close the file
    if (fclose(fp) != 0) {
        syslog(LOG_ERR, "Error: Could not close file '%s'", writefile);
        fprintf(stderr, "Error: Could not close file '%s'.\n", writefile);
        closelog();
        exit(1);
    }

    // Close syslog
    closelog();
    exit(0);
}
