<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
      
<body class="<?php print $section_class; print $body_classes; if (!empty($admin)) print ' admin' ?>">
  <?php if (!empty($admin)) print $admin; ?>
  <?php if (empty($admin)) { ?>
  <div id="aak-topbar">
    <div id="aak-topbar-inner">
      <a href="http://www.aarhuskommune.dk/"><?php print t("Go to aarhuskommmune.dk"); ?></a>
    </div>
  </div>
  <?php } ?>
  <div id="container" class="<?php print $classes; ?>">
		<div id="container-inner" <?php if($random_image_class): ?>class="<?php print $random_image_class; ?>"<?php endif; ?>>
     	<?php if ($site_name): ?>
          <h1 id="site-name">
            <?php print $site_name; ?>
            <a href="<?php print $header_link ?>"><span></span></a>
          </h1>
        <?php endif; ?>
      <?php print $secondary_menu; ?>
      <?php if ($header OR $header_isbanen): ?>
      	<div id="header-blocks" class="section region">
        	<div class="region-inner">
          	<?php print $header; ?>
            <?php print $header_isbanen; ?>
            <div id="subsite-menu"><?php print $subsite_menu; ?></div>
        	</div>
      	</div> <!-- /header-blocks -->
      <?php endif; ?>
      
   
    <div id="content">
    
    		<?php if ($banner): ?><div id="banner"><?php print $banner; ?></div><?php endif; ?>
        
        <div id="maincontent">

					<?php if ($content_top): ?>
            <div id="content-top" class="section region"><?php print $content_top; ?></div> <!-- /content-top -->
          <?php endif; ?>
  
          <?php if ($title): ?><h1 id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php if ($tabs): ?>
            <div class="local-tasks"><div class="clear-block">
              <?php print $tabs; ?>
            </div></div>
          <?php endif; ?>
          <?php if ($messages): print $messages; endif; ?>
          <?php if ($help): print $help; endif; ?>
  
          
					<?php print $content_subheading; ?>
  				<?php print $content; ?>

      </div>
  
			<?php if ($left): ?>
        <div id="sidebar-left" class="section sidebar region">
          <?php print $left; ?>
        </div> <!-- /sidebar-left -->
      <?php endif; ?>

      <?php if ($right): ?>
        <div id="sidebar-right" class="section sidebar region">
          <?php print $right; ?>
        </div> <!-- /sidebar-right -->
      <?php endif; ?>
    
  	</div> <!-- /content -->

	</div> <!-- /container-inner -->
</div> <!-- /container -->
<?php if ($footer or $footer_message): ?>
  <div id="footer" class="clear-block">
    <?php print $footer_message; ?><?php print $feed_icons; ?>
  </div> <!-- /footer -->
<?php endif; ?>

  <?php print $closure ?>

</body>
</html>