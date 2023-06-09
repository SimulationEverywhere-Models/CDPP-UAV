[top]
components : missionscript@missionscript fuelmonitor@fuelmonitor  
components : missionexecution
in : start stop
out : out
link : out out@missionexecution
link : out out@missionscript
link : out outoffuel@fuelmonitor
link : out@missionscript in@missionexecution
link : start in@missionscript
link : start in@fuelmonitor
link : outoffuel@fuelmonitor stop@missionscript
link : stop stop@missionscript
link : stop stop@fuelmonitor
link : stopexecution@missionscript stop@missionexecution
link : stopfueling@missionexecution stop@fuelmonitor

[missionexecution]
components : gotowaypoint@gotowaypoint search@search loiter@loiter track@track 
in : in stop
out : out stopfueling
link : in in@gotowaypoint
link : stop stop@search
link : stop stop@loiter
link : stop stop@track
link : stop stop@gotowaypoint
link : done@gotowaypoint in@search
link : done@gotowaypoint out
link : done@search in@loiter
link : done@search out
link : done@loiter in@track
link : done@loiter out
link : done@track stopfueling
link : done@track out


[missionscript]
preparation : 00:00:01:000 

[fuelmonitor]
preparation : 00:00:50:000 

[search]
preparation : 00:00:10:000 

[track]
preparation : 00:00:10:000 

[loiter]
preparation : 00:00:10:000 

[gotowaypoint]
preparation : 00:00:10:000 
