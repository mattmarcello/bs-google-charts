type node;

type chart;

/* [@bs.val] */
/* external listToDataTable : list((string, int)) => dataTable = */
/*   "google.visualization.arrayToDataTable"; */
[@bs.val] external getElementById : string => node = "document.getElementById";

[@bs.new] external createChart : node => chart = "google.charts.Bar";

[@bs.send]
external drawChart : (chart, DataTable.t, Options.t) => unit = "draw";

let component = ReasonReact.statelessComponent("Bar");

let make =
    (~id: string, ~dataTable: DataTable.t, ~options: Options.t, _children) => {
  ...component,
  didMount: _self =>
    createChart(getElementById(id))
    |> drawChart(_, dataTable, options)
    |> ignore,
  render: _self => <div id />,
};
