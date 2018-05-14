ReactDOMRe.renderToElementWithId(<Component1 message="Hello!" />, "index1");

ReactDOMRe.renderToElementWithId(
  <BsReactScriptLoader.Script url="https://www.gstatic.com/charts/loader.js">
    ...(
         remote =>
           switch (remote) {
           | Success =>
             <PackageLoader version=`Upcoming packages=[`Corechart, `Bar]>
               ...(
                    remote' =>
                      switch (remote') {
                      | Loading => ReasonReact.string("loading")
                      | Success => <BarChart id="my-cool-chart" />
                      }
                  )
             </PackageLoader>
           | NotAsked => ReasonReact.string("not asked")
           | Loading => ReasonReact.string("loading")
           | Failure => ReasonReact.string("failure")
           }
       )
  </BsReactScriptLoader.Script>,
  "index2",
);
