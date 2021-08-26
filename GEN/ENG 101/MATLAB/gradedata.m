%% Grade Data Assignment
% Nolan Anderson
% ENG 101
% 1/23/2019
clc
clear
clf
close all
 %% Given Data
students = 1:1:12;
ex1 = [100 80 25 45 89 65 92 75 76 25 80 50];
ex2 = [88 95 55 60 81 25 70 100 95 70 72 10];

%% Exam 1 80-89
question1 = sum(ex1>=80 & ex1<=89); % Finds the number of students that got between a 80 and 89 on exam 1
fprintf('\t %x Students scored between 80 and 89 on exam one.\n', question1)

%% Exam 2 Greater than 70
question2 = sum(ex2>=70); % Finds the number of students that did better than a 70 on exam 2
fprintf('\t %x students scored above 70 on exam two.\n', question2)

%% Average for each exam
avgex1 = mean(ex1); % Finds the average for exam 1
fprintf('\t The average for exam one is a %.2f.\n', avgex1)
avgex2 = mean(ex2); % Finds the average for exam 2
fprintf('\t The average for exam one is a %.2f.\n', avgex2)

%% Students who did better than the avgerage exam 1 & 2.
betterthanavg1 = sum(ex1>=avgex1);  % Finds the number of students that did better than the average for exam 1
betterthanavg2 = sum(ex2>=avgex2);  % Finds the number of students that did better than the average for exam 2
fprintf('%x Students scored above the average on exam one.\n' , betterthanavg1)
fprintf('%x students scored above the average on exam two.\n' , betterthanavg2)

%% Which students did better than the average on both and either exam.
fprintf('The following students scored above the average on both exams:\n')
a = ex1>=avgex1 & ex2>=avgex2; % makes a veriable that stores the true/false values for who did better than the average
b = students(a) % Takes the variable 'a' and and assigns student numbers to true(1) values found in 'a'
fprintf('The following students scored better than the average on either exam:')
c = ex1>=avgex1 | ex2>=avgex2; % Stores true false data on who did better on either exam than the averge into variable c
d = students(c) % Takes the variable 'c' and and assigns student numbers to true(1) values found in 'c'

