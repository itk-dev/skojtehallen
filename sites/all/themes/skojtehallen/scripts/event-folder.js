/* 
 * This JS file tries to make the "date repeat" output more manageable by using
 * Jquery to fold dates together. So the use can display theme, if he/she wiches.
 */

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    var root = $('.repeated-events')
    if (root.length > 0) {
      var repeats = $('.field-field-arrangement-start', root);
      repeats.hide();
      $('.field-label', root).addClass('event-link');
      $('.field-label', root).click(function() {
         repeats.slideToggle(600, function() {
          if ($(this).is(":visible")) {
            $('.field-label').addClass('item-open');
          }
          else {
            $('.field-label').removeClass('item-open');
          }
         });
      });
    }
  });
};


