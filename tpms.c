#include<stdio.h>
#include<stdlib.h>

struct hr_info{
    char fname[10];
    char lname[10];
    char cmpname [20];
    char empid [5];
    char user_name[20];
    char password[20];
    char job_openings[50];
    char training_programs[50];
    char internships[50];
    int num_job_openings;
    int num_training_programs;
    int num_internships;

};
struct cand_info{
    char fname[10];
    char lname[10];
    char email[20];
    char qualification[50];
    int cgpa;
    char job_category[50];
    char user_name[20];
    char password[20];

};
struct job_info{
    char job_title[20];
    char qualification[20];
    int cgpa;
    char salary[10];
    char location[];
}job;

//File Handling
void write(struct cand_info arr[], int size, const char* filename){
    FILE *file = fopen(filename,"w");
    if(file== NULL){
        printf("ERROR!");
    }
    int i;
    for(i=0;i<size;i++){
        fprintf(file,"%s %s %s %s %s %s %s",arr[i].fname,arr[i].lname,arr[i].email,arr[i].qualification,arr[i].job_category,arr[i].user_name,arr[i].password);
    }
    fclose(file);
};

// Global variables
struct hr_info hr_list[3];
struct cand_info cand_list[3];
int num_hr = 0;
int num_cand = 0;
struct job_info new_job[1];

// Function Prototype
int main();
void hr();
void candidate();
void hr_reg();
void cand_reg();
void login();
// void hr_menu();
void add_job_opening();
// void add_training_program(int hr_index);
// void add_internship(int hr_index);
// void view_jobs();
// void view_candidates();
// void apply_for_job(int candidate_index);
// void update_profile(int candidate_index);

// HR interface
void hr(){
    int a;
    printf("\nWelcome HR\n");
    printf("Press '1' for login\n");
    printf("Press '2' to register\n");
    printf("Press '3' to go to main menu\n");
    printf("Input: ");
    scanf("%d",&a);
    if(a==1){
        login();
    }else if(a==2){
        hr_reg();
    }else if(a==3){
        printf("\n");
        main();
    }else{
        printf("Invalid input!\n");
        return;
    }
};

// Candidate Interface
void candidate(){
    int a;
    printf("\nWelcome Candidate\n");
    printf("Press '1' for login\n");
    printf("Press '2' to register\n");
    printf("Press '3' to go to main menu\n");
    printf("Input: ");
    scanf("%d",&a);
    if(a==1){
    login();
    }else if(a==2){
        cand_reg();
    }else if(a==3){
        printf("\n");
        main();
    }
    else printf("Invalid Input!");
};

// Function for HR registration
void hr_reg(){
    struct hr_info new_hr;
    printf("\nWelcome to HR registration\n");
    int x;
    printf("Enter Your First Name: ");
    scanf("%s",new_hr.fname);
    printf("Enter Your Last Name: ");
    scanf("%s",new_hr.lname);
    printf("Enter Your Company Name: ");
    scanf("%s",new_hr.cmpname);
    printf("Enter Your Employee ID: ");
    scanf("%s",new_hr.empid);
    printf("Enter Your Username: ");
    scanf("%s",new_hr.user_name);
    printf("Enter Your Password: ");
    scanf("%s",new_hr.password);
    new_hr.num_job_openings = 0;
    new_hr.num_training_programs = 0;
    new_hr.num_internships = 0;

    // Add data to txt file
    FILE *fp;
    fp = fopen("hr.txt","w");
    fprintf(fp,"HR Info - \n\nName - %s %s\nCompany - %s\nEmployee ID - %s\nUsername - %s\nPassword - %s",new_hr.fname,new_hr.lname,new_hr.cmpname,new_hr.empid,new_hr.user_name,new_hr.password);
    fclose(fp);
    printf("\nWelcome %s, Your account has been created succesfully.",new_hr.fname);
    printf("\n\nDo you want add job openings");
    printf("\n1 - Yes\t2 - Exit\n");
    printf("Input: ");
    scanf("%d",&x);
    if(x==1){
        add_job_opening();
    }else if(x==2){
        printf("\nThankyou for using our Application");
        return;
    }else{
        printf("\nInvalid input");
        return;
    }
}
// Function for candidate registration
void cand_reg(){
    printf("\nCandidate Registration\n");
    struct cand_info new_cand;
    int x;
    printf("Enter Your First Name: ");
    scanf("%s",new_cand.fname);
    printf("Enter Your Last Name: ");
    scanf("%s",new_cand.lname);
    printf("Enter Your Email: ");
    scanf("%s",new_cand.email);
    printf("Enter Your qualification: ");
    scanf("%s",new_cand.qualification);
    printf("Enter Your cgpa: ");
    scanf("%d",&new_cand.cgpa);
    printf("Enter Your Job Category: ");
    scanf("%s",new_cand.job_category);
    printf("Enter Your Username: ");
    scanf("%s",new_cand.user_name);
    printf("Enter Your Password: ");
    scanf("%s",new_cand.password);



    // Add data to txt file
    FILE *fp;
    fp = fopen("candidate.txt","w");
    fprintf(fp,"Candidate Info - \n\nName - %s %s\nEmail - %s\nQualificattion - %s\nCGPA - %d\nJob Category - %s\nUsername - %s\nPassword - %s",new_cand.fname,new_cand.lname,new_cand.email,new_cand.qualification,new_cand.cgpa,new_cand.job_category,new_cand.user_name,new_cand.password);
    fclose(fp);

    
    printf("\nWelcome %s, Your account has been created succesfully.",new_cand.fname);
    
    
    
    if(new_cand.cgpa<job.cgpa){
        printf("\nSorry! You do not match the minimum criteria");
        printf("\n1 - Exit\t2 - Main Menu\n");
        int y;
        printf("Input: ");
        scanf("%d",&y);
        if(y==1){
            printf("\n\nThankyou for using our Application!\n");
            return;
        }else if(y==2){
            printf("\n");
            main();
        }else return;
    }else if(job.cgpa==0){
        printf("\nNo jobs matching your profile available at the moment!");
        printf("\n\nThankyou for using our Application!\n");
    }
    else {
        printf("\nCongratulations! You're eligible for interview");
        printf("\nDo you want to apply for the job opening?");
        printf("\n1 - Yes\t 2 - No\n");  
        scanf("%d",&x);
        if(x==1){
            printf("\nThanks for applying! You will be informed shortly");
            printf("\nThankyou for using our application");
    }else if (x==2){
        printf("\nThankyou for using our application");
    }else printf("\nInvalid input!");
    }
    return;
    

}

// Function for Login
void login(){
    printf("\nLogin module is in development phase!");
    printf("\nPlease register...\n\n");
    main();
        
};


void add_job_opening(){
    printf("\nAdd job title: ");
    scanf("%s",job.job_title);
    printf("\nAdd qualification: ");
    scanf("%s",job.qualification);
    printf("\nMin cgpa: ");
    scanf("%d",&job.cgpa);
    printf("\nAdd salary: ");
    scanf("%s",job.salary);
    printf("\nAdd location: ");
    scanf("%s",job.location);

    // Add data to txt file
    FILE *fp;
    fp = fopen("job.txt","w");
    fprintf(fp,"Job Description\n\nJob Title - %s\nQualification - %s\nCGPA required - %d\nSalary - %s\nLocation - %s",job.job_title,job.qualification,job.cgpa,job.salary,job.location);
    fclose(fp);

    printf("\nJob opening added successfully\n\n");
    main();
}

// Main Function
int main(){
    printf("\n****************************************************\n");
    printf("Welcome to Training and Placement management system\n");
    printf("****************************************************\n\n");
    int n;
    printf("You are a?\n");
    printf("1 - HR\t");
    printf("2 - Candidate\t");
    printf("3 - Exit\n");
    printf("Input: ");
    scanf("%d",&n);
    if(n==1){
        hr();
    }else if(n==2){
        candidate();
    }else if(n==3){
        printf("\nThanks for using our Application!\n");
    }else{
        printf("\nInvalid input! Please try again.\n\n");
        main();
    }
    return 0;
}