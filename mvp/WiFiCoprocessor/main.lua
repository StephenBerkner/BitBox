-- create timer object
timer = tmr.create()

-- wait until an ip is received before continuing
-- check every 1 second
tmr.alarm(0,1000, 1, function()
    if wifi.sta.getip() == nil then
    else
        ip, netmask, gateway = wifi.sta.getip()
        uart.write(0,ip.."\n")
        tmr.stop(0)
    end
end)

-- close server if an old one exists
if srv ~= nil then
    srv:close()
end

--create server without a timeout
srv = net.createServer(net.TCP)

-- listen on port 80
srv:listen(80,function(client)
    client:on("receive",function(client,request)
        function update()
            command = string.sub(request,parse[2]+1, #request)
            if command == "Busy" then

                timer:alarm(5000, tmr.ALARM_AUTO, function()
                    uart.write(0,"Busy\n")
                end)

            elseif command == "Available" then

                timer:alarm(5000, tmr.ALARM_AUTO, function()
                    uart.write(0,"Available\n")
                end)
                
            elseif command == "Stop" then
                timer:stop(0)
            end
        end

        parse = {string.find(request,"command=")}
        if parse[2] ~= nil then update() end

        page = "<html>\n<body>\n<h1> Open Source Sign Interface </h1>\n<button type=\"button\"><form action=\"\" method=\"POST\">\n"
        page = page.."<input type=\"submit\" name=\"command\" value=\"Busy\">\n<input type=\"submit\" name=\"command\" value=\"Available\">\n"
        page = page.."<input type=\"submit\" name=\"command\" value=\"Stop\">\n</form>\n</body>\n</html>"

        client:send(page)
        client:on("sent",function(client) client:close() end)

        
    end)
end)