--set baud rate to 2400
uart.setup(0, 2400, 8, uart.PARITY_NONE, uart.STOPBITS_1, 0)

-- set credentials using inc/credentials.lua
dofile("credentials.lua")
 
wifi.setmode(wifi.STATION)
wifi.sta.config{ssid=my_ssid, pwd=my_pwd}

dofile("main.lua")