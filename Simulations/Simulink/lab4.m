voltage_in =[6, 8, 12];
current_in=[0.190, 0.148, 0.102]; 
eff= (3.345*0.3)./(voltage_in.*current_in);

plot (voltage_in,100.*eff);
xlabel('Input Voltage(V)');
ylabel('Efficiency (%)');
title('Output Voltage vs Efficiency Graph of Regulated Buck Converter');
grid on;