%question 4
open_loop_G=tf( [4], [1 2 0]);
controller_C = tf( [40 40*5], [1 19]);

cltf = feedback( open_loop_G*controller_C, 1 )
%cltf = open_loop_G * controller_C / (1+ open_loop_G * controller_C);

% cltf = tf((160*s+800)/(s^3+21s^2+198s+800));
figure(1)
bode(open_loop_G)
%(160*s+800)/(s^3+21s^2+198s+800)

figure(2)
bode(cltf)

%this is a lead compensator

