<?php
drupal_set_header('Content-Type: text/xml; charset=utf-8');
print "<?xml version=\"1.0\" encoding=\"utf-8\"?>"; ?>
<data delay="4000">
  <frontImage>/sites/all/modules/custom/fading_banner/img/front.png</frontImage>
  <?php print $content; ?>
</data>