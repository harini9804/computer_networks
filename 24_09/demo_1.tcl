set x 10
set y $x
set z x+10
puts " x is $x "
puts " y is $y "
puts " z is $z "

set y [expr pow($x,2)]

if{$x > 0}
{return $x}
else{
  return [expr -$x]
}

while{$x>0}{
puts $x
incr x-1
}
