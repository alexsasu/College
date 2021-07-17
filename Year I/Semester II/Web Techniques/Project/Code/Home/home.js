window.onload = function() {
  if (localStorage.getItem("tips") == null) {
    var array = ["The combination \"Ctrl\" + \"Shift\" + \"T\", used in Google Chrome, reopens the last tab you've closed. If you've closed multiple tabs, you can press this shortcut key multiple times to restore each of the closed tabs.",
                "The mouse wheel is not only a wheel. It can also be used as a button. Pressing down on the wheel will act like a third mouse button. The wheel button can open a web page in a tab by pushing down the wheel on any link, and it can also close tabs, by pushing it down on any tab.", 
                "Hit Windows Key-Period(.) to pop up an expanded bottom-right menu of emojis, \"Kaimoji\" characters built from unicode characters, and a wide array of miscellaneous symbols.",
                "Sometimes trying to select an entire paragraph of text using your mouse can be difficult. However, there’s a mouse shortcut that allows you to select full paragraphs of text. Place the cursor at the beginning of the text you wish to select, then scroll down to the end. Hold down the \"Shift\" key, and then left-click where you want the selection to end.", 
                "Windows has a handy \"Snap To\" feature that will automatically move your mouse to buttons in the dialog box, such as the \"X\" to exit or the \"_\" to minimize. For example, to close a window, you may get a prompt asking if you really want to perform the task. With the \"Snap To\" feature, the mouse will automatically move to the \"OK\" button so that all you have to do is click if you agree. To enable this feature, open the \"Mouse properties\" under the \"Control Panel\", and check \"Snap To\" under the \"Pointer Options\" tab.", 
                "The combination \"Ctrl\" + \"Shift\" + \"Esc\" opens Windows Task Manager."];
    localStorage.setItem("tips", JSON.stringify(array));
  }
  else {
    localStorage.clear();
    location.reload();
  }

  var d = new Date();
  var t = d.getTime();
  var days = Math.floor(t / (86400000));

  var tips = JSON.parse(localStorage.getItem("tips"));
  var i = days % tips.length;

  document.getElementById("text1").innerHTML = document.getElementById("text1").innerHTML+" "+tips[i];
}