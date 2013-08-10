<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

/* 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

function template_preprocess_views_spin_carousel( &$vars ) {

   drupal_add_css(
      drupal_get_path( 'module', 'views_spin_carousel' ).
         '/views-spin-carousel.css'
   );

   if(
      !is_numeric( $vars['options']['flipper_width'] ) ||
      !is_numeric( $vars['options']['flipper_height'] )
   ) {
      // TODO: Error or something?
      return;
   }

   $panel_width = $vars['options']['flipper_width'];
   $panel_height = $vars['options']['flipper_height'];
   $panel_width_large = $panel_width + 10;
   $panel_height_large = $panel_height + 10;

   // Get the angles for the main carousel.
   $panel_count = count( $vars['view']->result );
   $tilt_inc = 360 / $panel_count;
   $tilt_z = round( ($panel_width_large / 2) / tan( pi() / $panel_count ) );

   // Add what we have so far.
   $panel_dynamic_css = <<<EOF
.views-spin-carousel-container-on {
   width: ${panel_width_large}px !important;
   height: ${panel_height_large}px !important;
}

.views-spin-carousel-flipper-on,
.views-spin-carousel-flipper-front-on,
.views-spin-carousel-flipper-back-on {
   width: ${panel_width}px !important;
   height: ${panel_height}px !important;
}
EOF;
   drupal_add_css( $panel_dynamic_css, 'inline' );
   drupal_add_js(
      array( 'viewsSpinCarousel' => array( 
         'panelWidth' => $panel_width,
         'panelClass' => '.views-spin-carousel-panel',
         'containerClass' => '.views-spin-carousel-container',
         'carouselClass' => '.views-spin-carousel',
         'flipperClass' => '.views-spin-carousel-flipper',
         'flipperFrontClass' => '.views-spin-carousel-flipper-front',
         'flipperBackClass' => '.views-spin-carousel-flipper-back',
         'tiltInc' => $tilt_inc,
         'tiltZ' => $tilt_z,
      ) ),
      'setting'
   );
   drupal_add_js(
      drupal_get_path( 'module', 'views_spin_carousel' ).
         '/views-spin-carousel.js'
   );

   // Add the carousel faces.
   $dynamic_css = '';
   for( $i = 0 ; $i < count( $vars['view']->result ) ; $i++ ) {
      $tilt_deg = $i * $tilt_inc;
      $transform_string = 'transform: rotateY( '.$tilt_deg.
         'deg ) translateZ( '.$tilt_z.'px );';
      $dynamic_css .= '.views-spin-carousel-panel-on:nth-child('.
         ($i + 1).') { '.
            $transform_string.
            '-moz-'.$transform_string.
            '-webkit-'.$transform_string.
            '}';
   }
   drupal_add_css( $dynamic_css, 'inline' );
}

