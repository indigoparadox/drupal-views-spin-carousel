
var viewsSpinCarouselTheta = 0;

jQuery(document).ready( function() {
   if( Modernizr.csstransforms3d ) {
      var settings = Drupal.settings.viewsSpinCarousel;

      // Only activate our fancy carousel if the browser can do 3D.
      jQuery( settings.containerClass )
         .addClass( 'views-spin-carousel-container-on' );
      jQuery( settings.carouselClass )
         .addClass( 'views-spin-carousel-on' );
      jQuery( settings.panelClass )
         .addClass( 'views-spin-carousel-panel-on' );
      
      jQuery( settings.flipperClass )
         .addClass( 'views-spin-carousel-flipper-on' );
      jQuery( settings.flipperFrontClass )
         .addClass( 'views-spin-carousel-flipper-front-on' );
      jQuery( settings.flipperBackClass )
         .addClass( 'views-spin-carousel-flipper-back-on' );

      jQuery('.views-spin-carousel-degrade').css( 'display', 'none' );

      jQuery('#content').append(
         '<a href="#" class="views-spin-carousel-link animated flipInX" ' +
            'id="views-spin-carousel-link-previous" ' +
            'onClick="return viewsSpinCarouselPrevious()">Previous</a>'
      );
      jQuery('#content').append(
         '<a href="#" class="views-spin-carousel-link animated flipInX" ' +
            'id="views-spin-carousel-link-next" ' +
            'onClick="return viewsSpinCarouselNext()">Next</a>'
      );
   }
} );

function viewsSpinCarouselPrevious() {
   // Calculate the transformation angle.
   if( 0 > viewsSpinCarouselTheta ) {
      viewsSpinCarouselTheta = 360;
   } else {
      viewsSpinCarouselTheta -= Drupal.settings.viewsSpinCarousel.tiltInc;
   }

   // Apply the transformation.
   // TODO: Do this by ID rather than class.
   jQuery( '.views-spin-carousel' ).
      css(
         'transform',
         'translateZ( 0px ) rotateY( ' +
            viewsSpinCarouselTheta.toString() +
            'deg )'
      );
   jQuery( '.views-spin-carousel' ).
      css(
         '-moz-transform',
         'translateZ( 0px ) rotateY( ' +
            viewsSpinCarouselTheta.toString() +
            'deg )'
      );
   jQuery( '.views-spin-carousel' ).
      css(
         '-webkit-transform',
         'translateZ( 0px ) rotateY( ' +
            viewsSpinCarouselTheta.toString() +
            'deg )'
      );

   return false;
}

function viewsSpinCarouselNext() {
   // Calculate the transformation angle.
   if( 360 < viewsSpinCarouselTheta ) {
      viewsSpinCarouselTheta = 0;
   } else {
      viewsSpinCarouselTheta += Drupal.settings.viewsSpinCarousel.tiltInc;
   }

   // Apply the transformation.
   jQuery( '.views-spin-carousel' ).
      css(
         'transform',
         'translateZ( 0px ) rotateY( ' +
            viewsSpinCarouselTheta.toString() +
            'deg )'
      );
   jQuery( '.views-spin-carousel' ).
      css(
         '-moz-transform',
         'translateZ( 0px ) rotateY( ' +
            viewsSpinCarouselTheta.toString() +
            'deg )'
      );
   jQuery( '.views-spin-carousel' ).
      css(
         '-webkit-transform',
         'translateZ( 0px ) rotateY( ' +
            viewsSpinCarouselTheta.toString() +
            'deg )'
      );

   return false;
}

function has3d() {
    var el = document.createElement('p'), 
        has3d,
        transforms = {
            'webkitTransform':'-webkit-transform',
            'OTransform':'-o-transform',
            'msTransform':'-ms-transform',
            'MozTransform':'-moz-transform',
            'transform':'transform'
        };

    // Add it to the body to get the computed style.
    document.body.insertBefore(el, null);

    for (var t in transforms) {
        if (el.style[t] !== undefined) {
            el.style[t] = "translate3d(1px,1px,1px)";
            has3d = window.getComputedStyle(el).getPropertyValue(transforms[t]);
        }
    }

    document.body.removeChild(el);

    return (has3d !== undefined && has3d.length > 0 && has3d !== "none");
}

