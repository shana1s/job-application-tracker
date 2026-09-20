Job Application Tracker

A program written in C to help keep track of job applications.

All the features:

- Add new job applications
- View all applications
- Search for applications by company
- Update application statuses
- View statistics for applied, interview, rejected, and offer statuses

How It Works:

Each job application you add stores the company name, position, and current status. Applications are stored using structs and an array, and the program uses a menu to let the user manage, search and view them.

Running the Program

Compile:

gcc tracker.c -o tracker

And Run:

./tracker

Future Improvements:

I would like to add file storage so applications are saved between sessions, and improve the search and filtering options.
