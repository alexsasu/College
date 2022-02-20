library(shiny)
library(shinyBS)



################
#   Triangle   #
################

triGen <- function(ratio)
{
  # the distance ratio, for each drawn point, to a certain
  # starting point (one of the red dots)
  distRatio <- ratio
  
  # the number of points that are to be drawn
  noPoints <- 50000
  
  # startingPts is a matrix that contains the coordinates of the
  # starting points (red dots), which will later be used to calculate
  # the coordinates of the points for each triangle
  startingPts <- matrix(NA, nrow = 3, ncol = 3)

  # the starting triangle is equilateral, having a side length of 2
  startingPts[1,] <- c(1, -1, -1)
  startingPts[2,] <- c(2, 0, sqrt(3)/2)
  startingPts[3,] <- c(3, 1, -1)
  
  # runif is used to uniformly distribute rational values between
  # 0 and 1 for the points that are to be calculated their coordinates
  verticesDistrib <- runif(noPoints)
  
  verticesDistrib[which(verticesDistrib <= 1/3)] <- 1
  verticesDistrib[which(1/3 < verticesDistrib & verticesDistrib <= 2/3)] <- 2
  verticesDistrib[which(verticesDistrib < 1)] <- 3

  # ptsCoords is a matrix that contains the coordinates of the points
  ptsCoords <- matrix(NA, ncol = 2, nrow = (noPoints + 1))

  # calculating the coordinates of the points
  ptsCoords[1,] <- c(runif(1, -1, 1), runif(1, -1, 1) * sqrt(3)/2)
  for (i in 2:noPoints) {
    ptNumber <- i
    
    ptSpot <- verticesDistrib[i]
    ptXAux <- startingPts[ptSpot, 2]
    ptYAux <- startingPts[ptSpot, 3]
    
    ptX <- distRatio * ptXAux + (1 - distRatio) * ptsCoords[i - 1, 1]
    ptY <- distRatio * ptYAux + (1 - distRatio) * ptsCoords[i - 1, 2]
    ptsCoords[ptNumber,] <- c(ptX, ptY)
  }
  
  return(list(startingPts, ptsCoords))
}



##############
#   Square   #
##############

squareGen <- function(ratio)
{
  # the distance ratio, for each drawn point, to a certain
  # starting point (one of the red dots)
  distRatio <- ratio
  
  # the number of points that are to be drawn
  noPoints <- 50000
  
  # startingPts is a matrix that contains the coordinates of the
  # starting points (red dots), which will later be used to calculate
  # the coordinates of the points for each square
  startingPts <- matrix(NA, nrow = 8, ncol = 3)
  
  # the starting square has a side length of 2
  startingPts[1,] <- c(1, -1.0, -1.0)
  startingPts[2,] <- c(2, 0.0, -1.0)
  startingPts[3,] <- c(3, 1.0, -1.0)
  startingPts[4,] <- c(4, 1.0, 0.0)
  startingPts[5,] <- c(5, 1.0, 1.0)
  startingPts[6,] <- c(6, 0.0, 1.0)
  startingPts[7,] <- c(7, -1.0, 1.0)
  startingPts[8,] <- c(8, -1.0, 0.0)

  # runif is used to uniformly distribute rational values between
  # 0 and 1 for the points that are to be calculated their coordinates
  verticesDistrib <- runif(noPoints)
  
  verticesDistrib[which(verticesDistrib <= 1/8)] <- 1
  verticesDistrib[which(1/8 < verticesDistrib & verticesDistrib <= 2/8)] <- 2
  verticesDistrib[which(2/8 < verticesDistrib & verticesDistrib <= 3/8)] <- 3
  verticesDistrib[which(3/8 < verticesDistrib & verticesDistrib <= 4/8)] <- 4
  verticesDistrib[which(4/8 < verticesDistrib & verticesDistrib <= 5/8)] <- 5
  verticesDistrib[which(5/8 < verticesDistrib & verticesDistrib <= 6/8)] <- 6
  verticesDistrib[which(6/8 < verticesDistrib & verticesDistrib <= 7/8)] <- 7
  verticesDistrib[which(verticesDistrib < 1)] <- 8
  
  # ptsCoords is a matrix that contains the coordinates of the points
  ptsCoords <- matrix(NA, ncol = 2, nrow = (noPoints + 1))
  
  # calculating the coordinates of the points
  ptsCoords[1,] <- c(-runif(1, -1, 1), runif(1, -1, 1))
  for (i in 2:noPoints) {
    ptNumber <- i
    
    ptSpot <- verticesDistrib[i]
    ptXAux <- startingPts[ptSpot, 2]
    ptYAux <- startingPts[ptSpot, 3]
    
    ptX <- distRatio * ptXAux + (1 - distRatio) * ptsCoords[i - 1, 1]
    ptY <- distRatio * ptYAux + (1 - distRatio) * ptsCoords[i - 1, 2]
    ptsCoords[ptNumber,] <- c(ptX, ptY)
  }
  
  return(list(startingPts, ptsCoords))
}



#########################
#   Restricted Square   #
#########################

resSquareGen <- function(ratio)
{
  # the distance ratio, for each drawn point, to a certain
  # starting point (one of the red dots)
  distRatio <- ratio
  
  # the number of points that are to be drawn
  noPoints <- 50000
  
  # startingPts is a matrix that contains the coordinates of the
  # starting points (red dots), which will later be used to calculate
  # the coordinates of the points for each square
  startingPts <- matrix(NA, nrow = 4, ncol = 3)
  
  # the starting square has a side length of 2
  startingPts[1,] <- c(1, -1.0, -1.0)
  startingPts[2,] <- c(2, 1.0, -1.0)
  startingPts[3,] <- c(3, 1.0, 1.0)
  startingPts[4,] <- c(4, -1.0, 1.0)

  # runif is used to uniformly distribute rational values between
  # 0 and 1 for the points that are to be calculated their coordinates
  verticesDistrib <- runif(noPoints)
  
  verticesDistrib[which(verticesDistrib <= 1/4)] <- 1
  verticesDistrib[which(1/4 < verticesDistrib & verticesDistrib <= 2/4)] <- 2
  verticesDistrib[which(2/4 < verticesDistrib & verticesDistrib <= 3/4)] <- 3
  verticesDistrib[which(verticesDistrib < 1)] <- 4
  
  # ptsCoords is a matrix that contains the coordinates of the points
  ptsCoords <- matrix(NA, ncol = 2, nrow = (noPoints + 1))

  # calculating the coordinates of the points
  ptsCoords[1,] <- c(-runif(1, -1, 1), runif(1, -1, 1))
  for (i in 2:noPoints) {
    ptNumber <- i
      
    avoidedVertex <- verticesDistrib[i - 1] + 1
    if (avoidedVertex == 5) {
      avoidedVertex <- 1
    }
    while (verticesDistrib[i] == avoidedVertex) {
        verticesDistrib[i] <- sample(1:4, 1)
    }
    ptSpot <- verticesDistrib[i]
    
    ptXAux <- startingPts[ptSpot, 2]
    ptYAux <- startingPts[ptSpot, 3]
    
    ptX <- distRatio * ptXAux + (1 - distRatio) * ptsCoords[i - 1, 1]
    ptY <- distRatio * ptYAux + (1 - distRatio) * ptsCoords[i - 1, 2]
    ptsCoords[ptNumber,] <- c(ptX, ptY)
  }
  
  return(list(startingPts, ptsCoords))
}



###########################
#   Restricted Pentagon   #
###########################

resPentGen <- function(ratio)
{
  # the distance ratio, for each drawn point, to a certain
  # starting point (one of the red dots)
  distRatio <- ratio
  
  # the number of points that are to be drawn
  noPoints <- 50000
  
  # startingPts is a matrix that contains the coordinates of the
  # starting points (red dots), which will later be used to calculate
  # the coordinates of the points for each pentagon
  startingPts <- matrix(NA, nrow = 5, ncol = 3)
  
  # coordinates for the starting pentagon (the one formed with red dots)
  pt1X <- 0.25 * (sqrt(10 + 2 * sqrt(5)))
  pt1Y <- 0.25 * (sqrt(5) - 1)
  pt2X <- 0.25 * (sqrt(10 - 2 * sqrt(5)))
  pt2Y <- 0.25 * (sqrt(5) + 1)
  
  # the starting pentagon has a side length of approximately 1.17
  startingPts[1,] <- c(1, 0, 1)
  startingPts[2,] <- c(2, pt1X, pt1Y)
  startingPts[3,] <- c(3, pt2X, -pt2Y)
  startingPts[4,] <- c(4, -pt2X, -pt2Y)
  startingPts[5,] <- c(5, -pt1X, pt1Y)
  
  # runif is used to uniformly distribute rational values between
  # 0 and 1 for the points that are to be calculated their coordinates
  verticesDistrib <- runif(noPoints)
  
  verticesDistrib[which(verticesDistrib <= 1/5)] <- 1
  verticesDistrib[which(1/5 < verticesDistrib & verticesDistrib <= 2/5)] <- 2
  verticesDistrib[which(2/5 < verticesDistrib & verticesDistrib <= 3/5)] <- 3
  verticesDistrib[which(3/5 < verticesDistrib & verticesDistrib <= 4/5)] <- 4
  verticesDistrib[which(verticesDistrib < 1)] <- 5
  
  # ptsCoords is a matrix that contains the coordinates of the points
  ptsCoords <- matrix(NA, ncol = 2, nrow = (noPoints + 1))
  
  # calculating the coordinates of the points
  ptsCoords[1,] <- c(runif(1, -pt1X, pt1X), runif(1, -pt2Y, 1))
  for (i in 2:noPoints) {
    ptNumber <- i
    
    while(verticesDistrib[i] == verticesDistrib[i - 1]) {
      verticesDistrib[i] <- sample(1:5, 1)
    }
    ptSpot <- verticesDistrib[i]
    
    ptXAux <- startingPts[ptSpot, 2]
    ptYAux <- startingPts[ptSpot, 3]
    
    ptX <- distRatio * ptXAux + (1 - distRatio) * ptsCoords[i - 1, 1]
    ptY <- distRatio * ptYAux + (1 - distRatio) * ptsCoords[i - 1, 2]
    ptsCoords[ptNumber,] <- c(ptX, ptY)
  }
  
  return(list(startingPts, ptsCoords))
}



###############
#   Hexagon   #
###############

hexGen <- function(ratio)
{
  # the distance ratio, for each drawn point, to a certain
  # starting point (one of the red dots)
  distRatio <- ratio
  
  # the number of points that are to be drawn
  noPoints <- 50000
  
  # startingPts is a matrix that contains the coordinates of the
  # starting points (red dots), which will later be used to calculate
  # the coordinates of the points for each hexagon
  startingPts <- matrix(NA, nrow = 6, ncol = 3)
  
  # coordinates for the starting hexagon (the one formed with red dots)
  ptHexagX <- sqrt(3)/2
  ptHexagY <- 0.5
  
  # the starting hexagon has a side length of 1
  startingPts[1,] <- c(1, 0, 2 * ptHexagY)
  startingPts[2,] <- c(2, ptHexagX, ptHexagY)
  startingPts[3,] <- c(3, ptHexagX, -ptHexagY)
  startingPts[4,] <- c(4, 0, -2 * ptHexagY)
  startingPts[5,] <- c(5, -ptHexagX, -ptHexagY)
  startingPts[6,] <- c(6, -ptHexagX, ptHexagY)
  
  # runif is used to uniformly distribute rational values between
  # 0 and 1 for the points that are to be calculated their coordinates
  verticesDistrib <- runif(noPoints)
  
  verticesDistrib[which(verticesDistrib <= 1/6)] <- 1
  verticesDistrib[which(1/6 < verticesDistrib & verticesDistrib <= 2/6)] <- 2
  verticesDistrib[which(2/6 < verticesDistrib & verticesDistrib <= 3/6)] <- 3
  verticesDistrib[which(3/6 < verticesDistrib & verticesDistrib <= 4/6)] <- 4
  verticesDistrib[which(4/6 < verticesDistrib & verticesDistrib <= 5/6)] <- 5
  verticesDistrib[which(verticesDistrib < 1)] <- 6
  
  # ptsCoords is a matrix that contains the coordinates of the points
  ptsCoords <- matrix(NA, ncol = 2, nrow = (noPoints + 1))
  
  # calculating the coordinates of the points
  ptsCoords[1,] <- c(runif(1, -ptHexagX, ptHexagX), runif(1, -2 * ptHexagY, 2 * ptHexagY))
  for (i in 2:noPoints) {
    ptNumber <- i
    
    ptSpot <- verticesDistrib[i]
    ptXAux <- startingPts[ptSpot, 2]
    ptYAux <- startingPts[ptSpot, 3]
    
    ptX <- distRatio * ptXAux + (1 - distRatio) * ptsCoords[i - 1, 1]
    ptY <- distRatio * ptYAux + (1 - distRatio) * ptsCoords[i - 1, 2]
    ptsCoords[ptNumber,] <- c(ptX, ptY)
  }
  
  return(list(startingPts, ptsCoords))
}



##################################
#   Barnsley (Cyclosorus) Fern   #
##################################

fernGen <- function()
{
  # the number of points that are to be drawn
  noPoints <- 50000
  
  # coef contains the coefficients resulted from each
  # equation of each affine transformation
  coef <- matrix(NA, ncol = 7, nrow = 4)

  coef[1,] <- c(1, 0.0,    0.0,    0.0,   0.25,  0.0,  -0.4)
  coef[2,] <- c(2, 0.95,   0.005, -0.005, 0.93, -0.002, 0.5)
  coef[3,] <- c(3, 0.035, -0.2,    0.16,  0.04, -0.09,  0.02)
  coef[4,] <- c(4, -0.04,  0.2,    0.16,  0.04,  0.083, 0.12)

  # runif is used to uniformly distribute rational values between
  # 0 and 1 for the points that are to be calculated their coordinates
  verticesDistrib <- runif(noPoints)
  
  verticesDistrib[which(verticesDistrib <= 2/100)] <- 1
  verticesDistrib[which(1/100 < verticesDistrib & verticesDistrib <= 86/100)] <- 2
  verticesDistrib[which(86/100 < verticesDistrib & verticesDistrib <= 93/100)] <- 3
  verticesDistrib[which(verticesDistrib < 1)] <- 4
  
  # ptsCoords is a matrix that contains the coordinates of the points
  ptsCoords <- matrix(NA, ncol = 2, nrow = (noPoints + 1))

  # calculating the coordinates of the points
  ptsCoords[1,] <- c(0, 0)
  for (i in 2:noPoints) {
    ptNumber <- i
    
    ptSpot <- verticesDistrib[i]
    ptX <- coef[ptSpot, 2] * ptsCoords[i - 1, 1] + coef[ptSpot, 3] * ptsCoords[i - 1, 2] + coef[ptSpot, 6]
    ptY <- coef[ptSpot, 4] * ptsCoords[i - 1, 1] + coef[ptSpot, 5] * ptsCoords[i - 1, 2] + coef[ptSpot, 7]
    ptsCoords[ptNumber,] <- c(ptX, ptY)
  }
  
  # the starting point (red dot) of the fern
  startingPt <- matrix(c(1, 0.0, 0.0), ncol = 3, nrow = 1)

  return(list(startingPt, ptsCoords))
}







##########################
#   Application Server   # 
##########################

server <- function(input, output, session) {
  output$figurePoints <- renderUI({
    input$figure
    sliderInput("pts",
                "Number of points:",
                min = 1,
                max = 50000,
                value = 1,
                step = 100,
                animate = animationOptions(interval = 400))
  })
  
  observeEvent(input$pts, {
    if (input$pts <= 500) {
      updateSliderInput(session,
                        "pts", 
                        step = 1)
    } else {
      updateSliderInput(session,
                        "pts", 
                        step = 100)
    }
  })
  
  updateButton(session, "genRandom", style = "primary", size = "default", disabled = FALSE)
  
  funcRet <- reactive({
    if (input$genRandom) {
      if (input$figure == "tri") {
        return(triGen(input$distTri))
      }
      if (input$figure == "sqr") {
        return(squareGen(input$distSqr))
      }
      if (input$figure == "resSqr") {
        return(resSquareGen(input$distResSqr))
      }
      if (input$figure == "resPent") {
        return(resPentGen(input$distResPent))
      }
      if (input$figure == "hex") {
        return(hexGen(input$distHex))
      }
      if (input$figure == "fern") {
        return(fernGen())
      }
    } else {
      if (input$figure == "tri") {
        return(triGen(input$distTri))
      }
      if (input$figure == "sqr") {
        return(squareGen(input$distSqr))
      }
      if (input$figure == "resSqr") {
        return(resSquareGen(input$distResSqr))
      }
      if (input$figure == "resPent") {
        return(resPentGen(input$distResPent))
      }
      if (input$figure == "hex") {
        return(hexGen(input$distHex))
      }
      if (input$figure == "fern") {
        return(fernGen())
      }
    }
  })
  
  output$figPlot <- renderPlot({
    startingPts <- funcRet()[[1]]
    ptsCoords <- funcRet()[[2]]

    par(mar=c(2, 2, 2, 2))
    if (input$figure != "fern") {
      plot(x = 0, y = 0, xlim = c(-1, 1), ylim = c(-1, 1), col = 0, xlab = "", ylab = "")
    } else {
      plot(x = 0, y = 0, xlim = c(-1.8, 1.8), ylim = c(0, 7), col = 0, xlab = "", ylab = "")
    }
      
    if (!is.null(input$pts)) { 
      if (input$pts != 0) {
        if (input$figure != "fern") {
          points(ptsCoords[1:input$pts, 1], ptsCoords[1:input$pts, 2], pch = 20, cex = 1, col = "blue")   
        } else {
          points(ptsCoords[1:input$pts, 1], ptsCoords[1:input$pts, 2], pch = 20, cex = 1, col = "green4")  
        }
      }
    }
    
    points(startingPts[,2], startingPts[,3], pch = 20, cex = 2, col = "red")
  })
}







######################
#   Application UI   # 
######################

ui <- fluidPage(
  h3("2D Chaos Game"),
  
  p("This two dimensional version of the Chaos Game consists of a set of
    2D figures, such as: triangles, squares, pentagons, hexagons and
    Barnsley (Cyclosorus) Ferns. These figures' starting vertices are
    marked with red dots, also called endpoints, inside the plot.
    The game begins by randomly generating a point marked with blue.
    By continuously generating blue points, based on the coordinates of 
    already generated blue points, and setting the right distance ratio 
    to the endpoints, we can achieve the selected figure itself, filled 
    with blue colored points, also known as a fractal. The more the 
    distance ratio is increased, the closer the fractals get to the 
    endpoints, also resulting in the defragmentation of the big fractal 
    in many small ones. The less the distance ratio is decreased, the 
    closer the fractals get to the center of the plot, resulting in
    the generation of a multitude of chaotic fractals."),

  br(),

  fluidRow(
    column(5,
           wellPanel(
              selectizeInput('figure',
                             h5(tags$b('2D Figure:')),
                             choices = list("Select a figure" = c('Triangle (Sierpinski Triangle)' = 'tri',
                                                                 'Square (Sierpinsky Carpet)' = 'sqr',
                                                                 'Restricted Square' = 'resSqr',
                                                                 'Restricted Pentagon' = 'resPent',
                                                                 'Hexagon (Sierpinski Hexagon)' = 'hex',
                                                                 'Barnsley (Cyclosorus) Fern' = 'fern')),
                             selected = 'tri'),
              
              conditionalPanel(
                condition = "input.figure == 'resSqr'",
                div(tags$b('Restriction:'),
                    " the currently processed vertex cannot be one place away clockwise from the previously chosen vertex.",
                    style = "font-size: 9.5pt", align = "left"),
                br()
              ),
              
              conditionalPanel(
                condition = "input.figure == 'resPent'",
                div(tags$b('Restriction:'),
                    " the currently processed vertex cannot be chosen in the next iteration.",
                    style = "font-size: 9.5pt", align = "left"),
                br()
              ),
             
              conditionalPanel(condition = "input.plotTab == 1",
                               div(uiOutput("figurePoints"))),
              
              div("For values between 1 and 500, the animation step is 1.",
                  tags$br(),
                  "For values over 500, the animation step is 100.",
                  style = "font-size: 9.5pt", align = "center"),
              
              br(),

              conditionalPanel(
                condition = "input.figure == 'tri'",
                sliderInput("distTri",
                            label = h5(tags$b("Distance ratio to starting point:")),
                            min = 0.01, max = 1, value = .50, step = .01,
                            animate = animationOptions(interval = 2000))
              ),
             
              conditionalPanel(
                condition = "input.figure == 'sqr'",
                sliderInput("distSqr",
                            label = h5(tags$b("Distance ratio to starting point:")),
                            min = 0.01, max = 1, value = .67, step = .01,
                            animate = animationOptions(interval = 2000))
              ),
              
              conditionalPanel(
                condition = "input.figure == 'resSqr'",
                sliderInput("distResSqr",
                            label = h5(tags$b("Distance ratio to starting point:")),
                            min = 0.01, max = 1, value = .50, step = .01,
                            animate = animationOptions(interval = 2000))
              ),
             
              conditionalPanel(
                condition = "input.figure == 'resPent'",
                sliderInput("distResPent",
                            label = h5(tags$b("Distance ratio to starting point:")),
                            min = 0.01, max = 1, value = .53, step = .01,
                            animate = animationOptions(interval = 2000))
              ),
             
              conditionalPanel(
                condition = "input.figure == 'hex'",
                sliderInput("distHex",
                            label = h5(tags$b("Distance ratio to starting point:")),
                            min = 0.01, max = 1, value = .67, step = .01,
                            animate = animationOptions(interval = 2000))
              ),

             div(bsButton("genRandom", label = "Randomize"), align = "center"),
             
             br(),
             
             div("Click", tags$b("Randomize"),
                 " to re-randomize the drawing based on the current settings.",
                 style = "font-size: 9.5pt", align = "center")
           )
    ),
    
    column(7,
           tabsetPanel(type = "tabs", id = "plotTab",
                       tabPanel("Plot of the selected figure", value = 1,
                                fluidRow(column(12,
                                                div(div(plotOutput("figPlot", height = '600px', width = '700px')), 
                                                    align = "center"
                                                   )
                                               )
                                        )
                               )
                      )
          )
  )
)



shinyApp(ui = ui, server = server)