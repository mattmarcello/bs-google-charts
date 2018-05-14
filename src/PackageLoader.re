[@bs.deriving jsConverter]
type version = [
  | [@bs.as "current"] `Current
  | [@bs.as "upcoming"] `Upcoming
];

[@bs.deriving jsConverter]
type package = [
  | [@bs.as "corechart"] `Corechart
  | [@bs.as "bar"] `Bar
  | [@bs.as "table"] `Table
  | [@bs.as "table"] `Sankey
];

[@bs.val]
external googleChartsLoad : (string, Js.t({..})) => unit =
  "google.charts.load";

[@bs.val]
external googleChartsSetOnLoadCallback : ((unit, unit) => unit) => unit =
  "google.charts.setOnLoadCallback";

type remote =
  | Loading
  | Success;

type state = {remote};

type action =
  | OnLoad;


let component = ReasonReact.reducerComponent("GoogleChart");

let make = (~version, ~packages: list(package), children) => {
  ...component,
  initialState: () => {remote: Loading},
  didMount: self => {
    googleChartsLoad(
      version |> versionToJs,
      {"packages": packages |> List.map(packageToJs) |> Array.of_list},
    );
    googleChartsSetOnLoadCallback(((), ()) => self.send(OnLoad));
  },
  reducer: (action, _state: state) =>
    switch (action) {
    | OnLoad => ReasonReact.Update({remote: Success})
    },
  render: self => children(self.state.remote),
};
