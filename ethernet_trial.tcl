set ns [new Simulator]

#open the NAM trace file
set nf [open prog.nam w]
$ns namtrace-all $nf

#open the trace file
set nd [open  prog.tr  w]
$ns trace-all $nd

#define a finish procedure
proc finish {} {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam prog.nam &
exit 0
}

#create 6 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

#create link between the nodes
$ns make-lan "$n0 $n1 $n2 $n3 $n4" 0.2Mb 40ms LL Queue/DropTail Mac/802_3

#setup a tcp connection
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink

#setup a FTP over a tcp connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 1.0 "$ftp start"
$ns at 5.0 "$ftp stop"
$ns at 5.5 "finish"
$ns run
