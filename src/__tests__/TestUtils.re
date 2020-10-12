open ReactTestingLibrary;

// from https://github.com/denis-ok/country-select/blob/master/__tests__/TestUtils.re

module Promise = {
  let map: ('a => 'b, Js.Promise.t('a)) => Js.Promise.t('b) =
    (f, p) => p |> Js.Promise.then_(a => Js.Promise.resolve(f(a)));

  let flatMap:
    ('a => Js.Promise.t('b), Js.Promise.t('a)) => Js.Promise.t('b) =
    (f, p) => p |> Js.Promise.then_(a => f(a));
};

module Event = {
  let click = FireEvent.click(~eventInit=?None);
};


