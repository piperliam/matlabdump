%in class work on 4/28/22 
%inverted pengulum on cart (from notes)


%you could input parameters such as mass or length of pendulum
clear variables; clc; close all;
A = [0 1 0 0;
    20.6 0 0 0;
    0 0 0 1;
    -0.5 0 0 0];
B =[0;-0.5;0;1];
C = [1 0 0 0];
D = 0; %peak forward term

ipoc_sys = ss(A,B,C,D)

[num, den] = ss2tf(A,B,C,D)

pidtool
