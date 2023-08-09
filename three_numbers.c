// Case		actions
// 1 2 3		=> no action
// 1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
// 2 1 3		-> sa  -> 1 2 3 => 1 action
// 2 3 1		-> rra -> 1 2 3 => 1 action
// 3 1 2		-> ra  -> 1 2 3 => 1 action
// 3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions