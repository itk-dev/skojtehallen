    <?php if (!$page): ?>
      <h2 class="node-title">
        <a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
        <?php print $unpublished; ?>
      </h2>
    <?php endif; ?>

    <?php if ($submitted): ?>
      <div class="node-submitted"><?php print $submitted; ?></div>
    <?php endif; ?>

    <?php print $picture; ?>

    <?php print $content; ?>
      <p class="back-to-overview">
        <a href="/nyheder">
          <?php print t('Back to overview'); ?>
        </a>
      </p>
      
    <?php if ($terms): ?>
      <div class="node-terms"><?php print $terms; ?></div>
    <?php endif; ?>

    <?php if ($links): ?>
      <div class="node-links"><?php print $links; ?></div>
    <?php endif; ?>
<!-- /node -->