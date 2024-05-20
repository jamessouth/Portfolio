type y;
type t;

[@bs.get] external isIntersecting: y => bool = "isIntersecting";
[@bs.new] external make: ((. array(y), t) => unit) => t = "IntersectionObserver";
[@bs.send] external observe: (t, Dom.element) => unit = "observe";
[@bs.send] external unobserve: (t, Dom.element) => unit = "unobserve";