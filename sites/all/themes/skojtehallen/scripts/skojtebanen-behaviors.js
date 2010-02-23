// Open selected external links in a new window
function openExternal() {
  $("a[rel='external']").click(function(){
    window.open(this.href);
    return false;
  });
}

// Enhance menu with slidedown effects
function menuEffects () {
  // Javascript enabled - disables css dropdowns
  $("body").addClass("jquery");
	
  // Add slidedown animation til main menu dropdowns
  $("#header-blocks .expanded").hoverIntent(
    function() {
      $(this).children(".menu").slideDown(300);
    },
    function() {
      $(this).children(".menu").fadeOut(400);
    }
    );
	
  // Add slideout animation on site switcher
  $("#subsite-menu a").hoverIntent(
    function() {
      $(this).animate({
        width: "27px"
      },150);
    },
    function() {
      $(this).animate({
        width: "19px"
      },400);
    }
    );
	
}

var skojtebanenFunctions = {
//  Fjerner default value i et inputfelt, n�r brugeren taster ind det.
	subLabels:function() {
		$(this).each(function() {
			
			// Skjul evt tilhørende labels til feltet og gem teksten fra label variabel
			var labeltext = $(this).val();
			
			// Check om der er sat labeltekst. Hvis ikke => enten tom label (fejl) eller ingen tilhørende label.
			if (labeltext == "") {
			
				// Spring videre til næste inputfelt
				return true;
			}
			$(this)
				
				// Bind funktion, der fjerne værdien ved focus
				.focus(function() {
					if ($(this).attr("value") == labeltext) {
						$(this).val("");
					};
				})
				
				// Sæt labeltekst tilbage on blur, hvis brugeren ikke har tastet noget
				.blur(function() {
					if ($(this).attr("value") == "") {
						$(this).val(labeltext);
					};
				})
		});
	}
};

function runOnStartup () {
  openExternal();
	menuEffects();
	$("input:text").each(skojtebanenFunctions.subLabels);
}


// Run startup functions on dom ready
$(document).ready(runOnStartup);

